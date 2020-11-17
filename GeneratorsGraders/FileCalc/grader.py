import os
import struct
import argparse
import random
import socket

class Grader:
    def __init__(self, feedback):
        self.feedback = feedback

    def __check_all__(self):
        score = 0
        public_method_names = [method for method in dir(self) if callable(getattr(self, method)) if not method.startswith('_')]
        for method in public_method_names:
            score += getattr(self, method)()

        return score, self.feedback

class EquationGrader(Grader):
    def __init__(self, equations, solutions):
        self.feedback = "\n[***] Testing Individual Equations [***]\n"
        super().__init__(self.feedback)
        self.operators = {
            0x01 : self.__addition__,
            0x02 : self.__subtract__,
            0x03 : self.__mult__,
            0x04 : self.__divide__,
            0x05 : self.__modulo__,
            0x06 : self.__and_bit__,
            0x07 : self.__or_bit__,
            0x08 : self.__xor_bit__,
        }

        self.equations = equations
        self.solutions = solutions

        # Rotate left: 0b1001 --> 0b0011
        self._rol_ = lambda val, r_bits, max_bits: \
            (val << r_bits%max_bits) & (2**max_bits-1) | \
            ((val & (2**max_bits-1)) >> (max_bits-(r_bits%max_bits)))
        
        # Rotate right: 0b1001 --> 0b1100
        self._ror_ = lambda val, r_bits, max_bits: \
            ((val & (2**max_bits-1)) >> r_bits%max_bits) | \
            (val << (max_bits-(r_bits%max_bits)) & (2**max_bits-1))

    def check_equations(self):
        grade = 0
        for index, equ in enumerate(self.equations):
            if equ[3] not in self.operators:
                self.feedback += "[*] Unsupported operator found: {}\n".format(hex(equ[1]))
                continue
            solution = self.operators[equ[3]](equ[2], equ[4])
            print(equ)
            if solution != self.solutions[index][2]:
                self.feedback += "[*] Solution is incorrect for equation. Expected: {} Got: {}\n".format(solution, self.solutions[index])
                continue

            self.feedback += "[+] Solution is correct for equation.\n"
            grade += 1

        return grade            

    def __addition__(self, op1, op2):
        return op1 + op2
    
    def __subtract__(self, op1, op2):
        return op1 - op2
    
    def __mult__(self, op1, op2):
        return op1 * op2
    
    def __divide__(self, op1, op2):
        return op1 // op2

    def __modulo__(self, op1, op2):
        return op1 % op2
    
    def __lsh__(self, op1, op2):
        return op1 << op2

    def __rsh__(self, op1, op2):
        return op1 >> op2

    def __and_bit__(self, op1, op2):
        return op1 & op2
    
    def __or_bit__(self, op1, op2):
        return op1 | op2

    def __xor_bit__(self, op1, op2):
        return op1 ^ op2

    def __rol_bit__(self, op1, op2):
        return self._rol_(op1, op2, 64)

    def __ror_bit__(self, op1, op2):
        return self._ror_(op1, op2, 64)

class EquParser:
    def __init__(self, equ_data, sol_data, opt_hdrs):
        self.opt_hdr_flags = {
            0x80 : self.__asym__,
            0x40 : self.__sym__,
            0x20 : self.__sec_signed__,
            0x10 : self.__comp__,
            0x08 : self.__serial__,
            0x04 : self.__not_impl__,
            0x02 : self.__not_impl__,
            0x01 : self.__not_impl__,
            0x00 : self.__not_set__
        }
        
        self.equ_data = equ_data
        self.sol_data = sol_data

        self.equations = []
        self.solutions = []
        self.feedback = "\n"
        
        #Iterate through all the hdrs and keys and dispatch the correct routine
        #TODO: Make sure encryption / signed is handled FIRST
        for opt_hdr in opt_hdrs:
            for key in self.opt_hdr_flags:
                feedback = self.opt_hdr_flags[opt_hdr.flags & key]()
                if type(feedback) is str:
                    self.feedback += feedback

    def chunks(self, lst, n):
        """Yield successive n-sized chunks from lst."""
        for i in range(0, len(lst), n):
            yield lst[i:i + n]

    def __not_set__(self):
        pass

    def __sec_signed__(self):
        raise NotImplementedError

    def __not_impl__(self):
        raise NotImplementedError

    def __asym__(self):
        raise NotImplementedError

    def __sym__(self):
        raise NotImplementedError

    def __comp__(self):
        raise NotImplementedError

    def __serial__(self):
        #Custom binary serialization
        #Get the equations
        equ_chunks = self.chunks(self.equ_data, 0x20)
        sol_chunks = self.chunks(self.sol_data, 0x10)
        #Should be the same number of equations as there are solutions
        #TODO: Update grade for equ_id to be 8 bytes!
        for equ, sol in zip(equ_chunks, sol_chunks):
            (equ_id, flags, operand1, operator, operand2) = struct.unpack("<IBQBQ", equ[:22])
            (equ_id2, flags2, solution) = struct.unpack("<IBQ", sol[:13])
            if equ_id != equ_id2:
                #Invalid parse assume error
                return "[*] Failed to parse equations #{}".format(hex(equ_id))
            
            self.equations.append((equ_id, flags, operand1, operator, operand2))
            self.solutions.append((equ_id, flags, solution))

        return "[+] All equations successfully parsed"

class EquHdr(Grader):
    def __init__(self, hdr, hdr2, project0):
        if project0:
            self.magic, self.file_id, self.num_equ, self.flags, self.equations_offset, self.num_opt_hdrs = struct.unpack("<IQQBIH", hdr)
            self.magic2, self.file_id2, self.num_equ2, self.flags2, self.equations_offset2, self.num_opt_hdrs2 = struct.unpack("<IQQBIH", hdr2)
        else:
            self.magic, self.num_equ, self.flags, self.equations_offset, self.num_opt_hdrs = struct.unpack("<IQBIH", hdr)
            self.magic2, self.num_equ2, self.flags2, self.equations_offset2, self.num_opt_hdrs2 = struct.unpack("<IQBIH", hdr2)

        self.feedback = "\n[***] Testing Equation Header [***]\n"
        super().__init__(self.feedback)

    def check_num_opr_hdrs(self):
        if self.num_opt_hdrs != self.num_opt_hdrs2:
            self.feedback += "[*] Number of optional headers don't match {} ----- {}".format(self.num_opt_hdrs, self.num_opt_hdrs2)
            return 0
        else:
            self.feedback += "[+] Number of optional headers match"
            return 2

    def check_magic(self):
        if self.magic2 != 0xdd77bb55 or self.magic != 0xdd77bb55:
            self.feedback += "[*] Failed Magic Test. Actual Value: {}\n".format(self.magic2)
            return 0
        else:
            self.feedback += "[+] Passed Magic Test\n"
            return 2
    
    def check_num_equs(self):
        if self.num_equ != self.num_equ2:
            self.feedback += "[*] Number of equations do not match {} ---- {}\n".format(self.num_equ, self.num_equ2)
            return 0
        else:
            self.feedback += "[+] Num Equations Match\n"
            return 2
    
    def check_flags(self):
        if (self.flags2 & 0x10 != 0x10):
            self.feedback += "[*] Solved Flag is not set\n"
            return 0
        else:
            self.feedback += "[+] Solved flag is set\n"
            return 4

class OptHdr(Grader):
    def __init__(self, opt_hdr, opt_hdr2, number):
        self.magic, self.len, self.flags = struct.unpack("<IHB", opt_hdr)
        self.magic2, self.len2, self.flags2 = struct.unpack("<IHB", opt_hdr2)
        self.feedback = "\n[***] Testing Optional Header {} [***]\n".format(number)
        self.data = b""
        self.data2 = b""
        super().__init__(self.feedback)

    def check_magic(self):
        if self.magic2 != 0xee88ff99 or self.magic != 0xee88ff99:
            self.feedback += "[*] Failed Magic Test. Actual Value: {}\n".format(self.magic2)
            return 0
        else:
            self.feedback += "[+] Passed Magic Test\n"
            return 2

    def check_len(self):
        if self.len != self.len2:
            self.feedback += "[*] Failed length test. Lengths don't match: {} ---- {}\n".format(self.len, self.len2)
            return 0
        else:
            self.feedback += "[+] Passed Length Test -- {}\n".format(self.len)
            return 2
    
    def check_flags(self):
        #Serialization algorithm
        if self.flags != self.flags2:
            self.feedback += "[*] Flags do not match. Flags: {} ---- {}\n".format(self.flags, self.flags2)
            return 0
        else:
            self.feedback += "[+] Flags Match\n"
            if self.flags2 & 0x01 and (self.len != 1 or self.len2 != 1):
                self.feedback += "[*] Failed to supply the proper length. Data Length: {} ---- {}\n".format(self.len, self.len2)
                return 2
            else:
                self.feedback += "[+] Supplied proper length for Serialization: {}\n".format(self.len2)
                return 4

class GradeFile:
    def __init__(self, unsolved_file, solved_file, project0):
        self.in_fd = open(unsolved_file, "rb")
        self.out_fd = open(solved_file, "rb")
        self.grade = 0
        self.feedback = ""
        self.project0 = project0
        self.grader_equ = None
        self.fatal = False
        self.opt_hdrs = []

        #Grade the three parts
        self.grade += self.grade_equ_hdr()
        if self.fatal:
            self.feedback += "\n[*] FATAL ERROR IN EQU HEADER SEE ABOVE FEEDBACK"
            return None
        self.grade += self.grade_opt_hdr()
        if self.fatal:
            self.feedback += "\n[*] FATAL ERROR IN OPT HEADER SEE ABOVE FEEDBACK"
            return None
        self.grade += self.grade_equations()
        if self.fatal:
            self.feedback += "\n[*] FATAL ERROR IN PARSING EQUATIONS SEE ABOVE FEEDBACK"
            return None

    def grade_report(self):
        return self.grade, self.feedback

    def grade_equ_hdr(self):
        if self.project0:
            equ_hdr_in = self.in_fd.read(27)
            equ_hdr_out = self.out_fd.read(27)
        else:
            equ_hdr_in = self.in_fd.read(19)
            equ_hdr_out = self.out_fd.read(19)
        
        self.grader_equ = EquHdr(equ_hdr_in, equ_hdr_out, self.project0)
        grade, feedback = self.grader_equ.__check_all__()
        self.feedback += feedback
        if '[*]' in self.feedback:
            self.fatal = True

        return grade
    
    def __opt_hdr_data__(self, opt_hdr):
        opt_hdr.data = self.in_fd.read(opt_hdr.len)
        opt_hdr.data2 = self.out_fd.read(opt_hdr.len2)
        if opt_hdr.data != opt_hdr.data2:
            self.feedback += "[*] Data is NOT equal between optional headers {} -- {}".format(opt_hdr.data,opt_hdr.data2)
            return 0
        else:
            self.feedback += "[+] Data is equal between optional headers"
            return 2

    def grade_opt_hdr(self):
        overall_grade = 0
        for index in range(self.grader_equ.num_opt_hdrs):
            opt_hdr = OptHdr(self.in_fd.read(7), self.out_fd.read(7), index)
            self.opt_hdrs.append(opt_hdr)
            grade, feedback = opt_hdr.__check_all__()
            self.feedback += feedback
            overall_grade += grade
            self.__opt_hdr_data__(opt_hdr)
            if '[*]' in self.feedback:
                self.fatal = True

        return overall_grade

    def grade_equations(self):
        grade = 0
        equ_sol_parsed = EquParser(self.in_fd.read(), self.out_fd.read(), self.opt_hdrs)
        self.feedback += equ_sol_parsed.feedback
        if '[*]' in self.feedback:
            self.fatal = True
            return grade

        equ_grader = EquationGrader(equ_sol_parsed.equations, equ_sol_parsed.solutions)
        grade, feedback = equ_grader.__check_all__()
        self.feedback += feedback
        if '[*]' in self.feedback:
                self.fatal = True

        return grade

def str2bool(v):
    if isinstance(v, bool):
       return v
    if v.lower() in ('yes', 'true', 't', 'y', '1'):
        return True
    elif v.lower() in ('no', 'false', 'f', 'n', '0'):
        return False
    else:
        raise argparse.ArgumentTypeError('Boolean value expected.')

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("unsolved", type=str, help="Unsolved File Directory")
    parser.add_argument("solved", type=str, help="Unsolved File Directory")
    parser.add_argument("--project0", type=str2bool, nargs='?', const=True, default=False, help="Only use this if you are grading project0")
    args = parser.parse_args()

    project0 = True #args.project0
    if project0:
        print("Grading Project 0")

    for unsolve, solve in zip(os.listdir(args.unsolved), os.listdir(args.solved)):
        grader = GradeFile(os.path.join(args.unsolved, unsolve), os.path.join(args.solved, solve), project0)
        score, feedback = grader.grade_report()
        print("[****] SCORE: {}".format(score))
        print("[****] FEEDBACK: {}".format(feedback))

if __name__ == "__main__":
    main()
