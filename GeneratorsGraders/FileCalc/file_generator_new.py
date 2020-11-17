import os
import struct
import argparse
import random

operators = {
    0x01 : 'add',
    0x02 : 'sub',
    0x03 : 'mult',
    0x04 : 'div',
    0x05 : 'mod',
    0x06 : 'and',
    0x07 : 'or',
    0x08 : 'xor',
}

file_hdr_flags = {
    'comp' : 7,
    'serial' : 6,
    'enc' : 5,
    'solved' : 4,
    'reserved0' : 3,
    'reserved1' : 2,
    'reserved2' : 1,
    'reserved3' : 0
}

opt_hdr_flags = {
    'asym_key' : 7,
    'sym_key' : 6,
    'sec_signed' : 5,
    'comp' : 4,
    'serial' : 3,
    'reserved0' : 2,
    'reserved1' : 1,
    'reserved2' : 0
}

equ_notation = {
    'prefix' : 1,
    'infinx' : 2,
    'postfix' : 3,
}

#Generates the FULL header and file based on parameters
class CalcHdr:
    def __init__(self, num_equ, enc, comp, serial):
        self.magic = 0xdd77bb55
        self.num_equ = num_equ
        self.file_id = os.urandom(8)
        self.flags = 0
        self.calc_flags(comp, serial, enc, False)
        
        self.equ_offset = 0
        self.num_opt_hdrs = 0
        self.optional_hdrs = []
        if enc:
            pass
        elif comp:
            pass
        elif serial:
            self.optional_hdrs.append(CalcOptHdr("serial", b"\x02"))
        else:
            self.optional_hdrs.append(CalcOptHdr(None, b"\x00"*8))
        
        self.equ_generator = CalcEquHdr()

    def set_flag(self, num):
        if num > 7 or num < 0:
            return

        self.flags |= ((self.flags >> num) | 0x1) << num

    def calc_flags(self, comp, serial, enc, solved):
        if comp:
            self.set_flag(file_hdr_flags['comp'])
        if serial:
            self.set_flag(file_hdr_flags['serial'])
        if enc:
            self.set_flag(file_hdr_flags['enc'])
        if solved:
            self.set_flag(file_hdr_flags['solved'])


    def calc_equ_offset(self, opt_hdr_size):
        offset = 0
        offset += 0x1b #Size of File Header
        offset += opt_hdr_size
        #print("[*] Debug: Opt Hdr size: {} Offset: {}".format(opt_hdr_size, offset))
        return struct.pack("<I", offset)

    def gen_file(self, file_id):
        #Need to calc the opt_hdrs first to get offset to equs
        opt_hdr = b""
        for hdr in self.optional_hdrs:
            opt_hdr += hdr.gen_hdrs()
        
        hdr = b""
        hdr += struct.pack("<I", self.magic)
        hdr += self.file_id
        hdr += struct.pack("<Q", self.num_equ)
        hdr += bytes(chr(self.flags), 'utf-8')
        hdr += self.calc_equ_offset(len(opt_hdr))
        hdr += struct.pack("<H", len(self.optional_hdrs))

        equs = self.gen_equs()

        return hdr + opt_hdr + equs

    def gen_equs(self):
        equs = b""

        for i in range(self.num_equ):
            self.equ_generator.gen_equ(False) # Generate Non-Float equations for now
            equs += self.equ_generator.gen_gimme_equ()

        return equs

class CalcOptHdr:
    def __init__(self, opt_type, data):
        self.magic = 0xee88ff99
        self.len = 0
        self.flags = 0
        self.data = bytes(data)
        self.opt_type = opt_type

    def set_flag(self, num):
        if num > 7 or num < 0:
            return
        
        self.flags |= ((self.flags >> num) | 0x1) << num

    def gen_opt_hdr(self):
        if self.opt_type == None:
            self.len = len(self.data)
            self.flags = 0
        elif self.opt_type == "serial":
            self.len = len(self.data)
            self.set_flag(opt_hdr_flags['serial'])
        else:
            pass

    def gen_hdrs(self):
        self.gen_opt_hdr()

        hdr = b""
        hdr += struct.pack("<I", self.magic)
        hdr += struct.pack("<H", self.len)
        hdr += bytes(chr(self.flags), 'utf-8')
        hdr += self.data

        return hdr

#Generates a SINGLE formatted equation
class CalcEquHdr:
    def __init__(self):
        self.equ_bytes = b""
        self.equ = CalcEqu()
        self.notation = 2 #random.randint(1, 3)

    def gen_equ(self, float_t):
        if float_t:
            self.flags = bytes(chr(0x01), 'utf-8')
        else:
            self.flags = bytes(chr(0x00), 'utf-8')

        self.equ.gen_equ_real(float_t)
        self.equ_bytes = self.equ.gen_gimme(self.notation)

    def gen_gimme_equ(self):
        equ_full = b""
        equ_full += os.urandom(4)
        equ_full += self.flags
        #equ_full += struct.pack("<B", self.notation)
        equ_full += self.equ_bytes
        #Pad out to 32 bytes
        if len(equ_full) < 32:
            for i in range(32 % len(equ_full)):
                equ_full += b"\x00"

        return equ_full

class CalcEqu:
    def __init__(self):
        self.operand1 = 0
        self.operator = 0
        self.operand2 = 0
        self.tell_me_what = random.randint(1,10)

    def gen_reset(self):
        self.operand1 = 0 
        self.operator = 0 
        self.operand2 = 0 
        self.tell_me_what = 0 #random.randint(1,10)

    def gen_equ_real(self, float_t):
        equ_type = 1
        #Make a float equation
        if float_t:
            pass
        #Make a rotate problem
        elif equ_type == 2:
            pass
        #Make a reguler integer problem
        else:
            self.operand1 = random.randint(1, 9223372036854775807)
            self.operand2 = random.randint(1, 9223372036854775807)
            self.operator = bytes(chr(random.randint(1,8)), 'utf-8')

    def gen_gimme(self, notation):
        equ = b""
        #rand_format = random.randint(1,4)
        if notation == 2:
            equ += struct.pack("<Q", self.operand1)
            equ += bytes(self.operator)
            equ += struct.pack("<Q", self.operand2)
            equ += struct.pack("<I", 0x00000000)
        elif notation == 1:
            pass
            #equ += bytes(self.operator)
            #equ += struct.pack("<Q", self.operand1)
            #equ += struct.pack("<Q", self.operand2)
            #equ += struct.pack("<I", 0x00000000)
        else:
            pass
            #equ += struct.pack("<Q", self.operand1)
            #equ += struct.pack("<Q", self.operand2)
            #equ += bytes(self.operator)
            #equ += struct.pack("<I", 0x00000000)
        #print("[*] Debug: {}".format(equ))
        return equ

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--output-dir", help="output directory for all the files. note default is current dir and will replace all .equ files")
    parser.add_argument("--num-files", help="number of files to generate. max is 2048. default is 16")
    parser.add_argument("--num-equ", help="number of equations per file. max is 4096. default is 64")
    args = parser.parse_args()

    output_dir = "."

    if args.output_dir:
        try:
            os.mkdir(args.output_dir)
            output_dir = args.output_dir

        except:
            output_dir = args.output_dir

    num_files = 16
    num_equ = 64
    
    if args.num_files and args.num_equ and (int(args.num_files) > 2048 or int(args.num_equ) > 4096):
        print("[!] Bad arguments. Use --help to learn")
        exit(-1)

    if args.num_files:
        num_files = int(args.num_files)

    if args.num_equ:
        num_equ = int(args.num_equ)

    generator = CalcHdr(num_equ, False, False, True)
    for i in range(num_files):
        with open("{}/file{}.equ".format(output_dir, i), "wb") as fd:
            fd.write(generator.gen_file(os.urandom(4)))

        print("[+] Generated: {}/file{}.equ".format(output_dir, i))

if __name__ == "__main__":
    main()
