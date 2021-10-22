import struct
import os
import socket
import time
import EquGrader

NET_HDR_SZ = 48
NET_FNAME_MAX = 24


def gen_net_hdr(pkt_len, efile_name_len):
    hdr = b""
    hdr_len = 40
    filename_len = efile_name_len
    pkt_len = pkt_len + NET_HDR_SZ
    filename = "TEST_NAME".ljust(NET_FNAME_MAX, "\x00")

    hdr = struct.pack("!IIQ", hdr_len, filename_len, pkt_len)
    hdr += filename.encode('utf-8')

    return hdr

INVALID_HDR_RSP = struct.pack("!I", NET_HDR_SZ).ljust(NET_HDR_SZ, b"\x00") #sends back just the hdr size

def check_nethdr_handling():

    tests_passed = 0

    hdrs = [(gen_net_hdr(100, 40), INVALID_HDR_RSP)]

    for h in hdrs:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect(("127.0.0.1", 31337))
            s.send(h[0])
            data = s.recv(1024)
            if data == h[1]:
                tests_passed += 1
    
    return (len(hdrs) - tests_passed)
        
        
def run_binary():
    os.chdir("./5_NetCalc")
    os.system("./build.sh")
    print("Starting server in background")
    os.system("./build/netcalc &") # start server in background
    time.sleep(1) #ensure server spinup
    try:
        check_nethdr_handling()
    except ConnectionRefusedError:
        print("Failed to connect to server; Aborting further tests")
        exit(-100)
    
    if not os.path.exists("client/client.py"):
        print("client.py not found; verify location")
        exit(-100)

    os.system("python3 client/client.py -i ../netcalc_tests/unsolved -o ../netcalc_tests/solved")
    os.system("pkill netcalc")
    os.chdir("../")


def main():
    result = 0
    tests_base =  "./netcalc_tests/"
    num_files = 16
    num_equ = 64

    EquGrader.setup(tests_base, num_files, num_equ)
    run_binary()
    result = EquGrader.grade_dirs(tests_base)
    EquGrader.cleanup(tests_base)

    return result


if __name__ == "__main__":
    main()