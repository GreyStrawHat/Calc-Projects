#!/usr/bin/python3

import sys
import os
import socket
import struct

NET_HDR_SZ = 48
NET_FNAME_MAX = 24
NET_NAME_FIELD_SZ = 32

def gen_net_hdr(pkt, efile):
    hdr = b""
    hdr_len = NET_HDR_SZ
    filename_len = len(os.path.basename(efile))
    pkt_len = len(pkt) + NET_HDR_SZ
    filename = os.path.basename(efile)[:NET_FNAME_MAX].ljust(NET_NAME_FIELD_SZ, "\x00")

    hdr = struct.pack("!IIQ", hdr_len, filename_len, pkt_len)
    hdr += filename.encode('utf-8')

    return hdr


def gen_equ_pkt(efile):
    pkt = b""
    with open(efile, "rb") as ef:
        pkt = ef.read()
    return pkt

def process_file(ip, port, efile):
    pkt = b""
    equ_packet = gen_equ_pkt(efile)
    net_hdr = gen_net_hdr(equ_packet, efile)
    pkt = net_hdr + equ_packet
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((ip, port))
        s.sendall(pkt)
        data = s.recv(1024)
        
    return data

def main():

    server_ip = "127.0.0.1"
    server_port = "31337"
    in_dir = sys.argv[2]
    out_dir = sys.argv[4]

    print(f"Sending file from {in_dir} storing in {out_dir}")

    for f in os.listdir(in_dir):
        data = process_file(server_ip, int(server_port), f"{in_dir}/{f}")
        if f[0] == '.':
            continue
        with open(f"{out_dir}/{f}", "wb") as of:
            of.write(data)
            


if __name__ == "__main__":
    main()