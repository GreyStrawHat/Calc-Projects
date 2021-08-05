
#!/bin/python3
import time
import sys
from subprocess import Popen, PIPE
import os
import string

FAIL = -1
PASS = 0

bin_loc = "SimpleCalc/build/simplecalc"
test_loc = "tests/SimpleCalc.tests"

def test_input(op1, operator, op2, ans):
    p = Popen([bin_loc, op1, operator, op2], stdin=PIPE, stdout=PIPE, stderr=PIPE)
    output, err = p.communicate()
    str_out = output.decode("ascii")

    # if failure occurs, assume first char in error message not decimal
    if (ans == "FAIL"):
        if len(output) == 0:
            return PASS
        elif len(err) != 0:
            return PASS
        elif str_out[0] not in string.digits:
            return PASS
        else:
            print("Failing Output")
            print(output)
            print(err)
            return FAIL
    else:
        if (ans in str_out):
            return PASS
        else:
            print("Failing Output")
            print(output)
            print(err)
            return FAIL

def main():
    numtests = 0
    numpassed = 0

    with open(test_loc, "r") as tf:
        for equ in tf:
            numtests += 1
            #print(f"Testing: {equ.strip()}")
            op1, operator, op2, ans = equ.strip().split(" ")
            res = test_input(op1, operator, op2, ans)
            numpassed = numpassed + 1 if PASS == res else numpassed

            if res == FAIL:
                print(f"Failed: {equ.strip()}\n")


    print("\nPassed {} out of {} ".format(numpassed, numtests))

    ret = 0 if numtests == numpassed else -1

    exit(ret)


if __name__ == "__main__":
    main()