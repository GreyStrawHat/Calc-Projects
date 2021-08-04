import sys
import argparse
import random
import struct
import os

from FileCalc_Generator import operators, EQU_HDR_MAGIC, EQU_HDR_SIZE, SER_EQU_SIZE, file_hdr_flags


class EquGrader():

    def __init__(self, infile, solfile):
        self.infile_name = infile
        self.solfile_name = solfile
        self.infile = open(infile, "rb")
        self.solfile = open(solfile, "rb")

        self.in_contents = self.infile.read()
        self.sol_contents = self.solfile.read()

        self.equ_offset = 0

        self.num_opt_hdrs = 0

        self.num_equs = 0

        self.errors = []


    def check_header(self):
        # check magic
        if self.sol_contents[:4] != struct.pack("<I", EQU_HDR_MAGIC):
            self.errors.append("[-] Invalid Header Magic")

        # check file id
        if self.sol_contents[4:12] != self.in_contents[4:12]:
            self.errors.append("[-] Invalid File ID")

        # flags is set to solved
        if self.sol_contents[20] != ord(file_hdr_flags["solved"]):
            print(self.sol_contents[8])
            self.errors.append("[-] Flags not set to \"solved\"")

        self.num_equs = struct.unpack("<Q", self.in_contents[12:20])[0]
        if self.num_equs == 0:
            self.errors.append("[-] Got 0 equations")

        num_out_equs = struct.unpack("<Q", self.sol_contents[12:20])[0]
        if self.num_equs != num_out_equs:
            self.errors.append("[-] Equations in do not match Equations out")

        self.equ_offset = struct.unpack("<I", self.in_contents[21:25])[0]
        if self.equ_offset != EQU_HDR_SIZE:
            self.errors.append("[-] Equation Offset Incorrect for FileCalc")

        self.num_opt_hdrs = struct.unpack("<H", self.in_contents[25:27])[0]
        if self.num_opt_hdrs != 0:
            self.errors.append("[-] FileCalc expects no OptHdrs")

        return 0

    def solver(self, op1, op2, func):
        if func == ord(operators['add']):
            return op1 + op2

        elif func == ord(operators['sub']):
            return op1 - op2

        elif func == ord(operators['mult']):
            return op1 * op2

        elif func == ord(operators['div']):
            return op1 / op2

        else:
            self.errors.append(f"[-] Invalid Function {func}")
            return False


    def check_solutions(self):
        n = SER_EQU_SIZE
        m = 13 # solved EQ size

        try:
            eq_d = {} # dict for equations read from input file; we solved these
            sol_d = {} # dict for answers read from solutions file; solutions read

            # read in solves, split them, break them down into dict by id
            sol_eq = self.sol_contents[self.equ_offset:]
            list_sol_eq = [sol_eq[i:i+m] for i in range(0, len(sol_eq), m)]

            for sol_eq in list_sol_eq:
                eid = struct.unpack("<I", sol_eq[:4])[0]
                error = sol_eq[4]
                answer = struct.unpack("<Q", sol_eq[5:])[0]
                sol_d[eid] = (error, answer)

            # read in eques, split them, break them down into dict by id
            in_eq = self.in_contents[self.equ_offset:]
            list_in_eq = [in_eq[i:i+n] for i in range(0, len(in_eq), n)]

            for whole_eq in list_in_eq:
                eid = struct.unpack("<I", whole_eq[:4])[0]
                eq = whole_eq[5:-10] # solve this
                func = eq[8]
                if func in range(6):
                    op1 = struct.unpack("<q", eq[:8])[0]
                    op2 = struct.unpack("<q", eq[9:])[0]
                    print("rewritting eid")
                    print(sol_d[eid])
                    sol_d[eid] = (sol_d[eid][0], sol_d[eid][1]+(2**64))
                    print(sol_d[eid])

                else:
                    op1 = struct.unpack("<Q", eq[:8])[0]
                    op2 = struct.unpack("<Q", eq[9:])[0]
                solution = self.solver(op1, op2, func)
                if solution > sys.maxsize:
                    solution = False
                eq_d[eid] = solution

            for eid in eq_d.keys():
                if eq_d[eid] == False and sol_d[eid][0] != 1:
                    self.errors.append(f"EQ {hex(eid)} did not match\n\tGot {sol_d[eid]} - Exp \"Failed\"")
                if eq_d[eid] != sol_d[eid][1]:
                    self.errors.append((f"EQ {hex(eid)} did not match\n\tGot {sol_d[eid]} - Exp {eq_d[eid]}"))
       
        except Exception as e:
            print(e)
            self.errors.append((f"Failed to parse {self.infile.name}"))

        return 0



    def print_errors(self):
        if len(self.errors) == 0:
            print(f"{self.solfile_name} passed all checks!")
            return 1
        else:
            print(f"{self.solfile_name} contains {len(self.errors)} errors")
            for x in self.errors:
                print(x)
            return 0

        


            
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("unsolved", type=str, help="Unsolved Directory")
    parser.add_argument("solved", type=str, help="Solved Directory")
    args = parser.parse_args()

    num_files = 0
    num_passed = 0

    for unsolve, solve in zip(os.listdir(args.unsolved), os.listdir(args.solved)):
        #print(f"Checking {args.unsolved}/{unsolve} against {args.solved}/{solve}")
        cf = EquGrader(f"{args.unsolved}/{unsolve}", f"{args.solved}/{solve}")
        cf.check_header()
        cf.check_solutions()

        num_files += 1
        num_passed += cf.print_errors()

    print(f"Test Results: {num_passed}/{num_files}")

    # returns negative failure on non passing tests
    exit((num_passed - num_files))



if __name__ == "__main__":
    main()