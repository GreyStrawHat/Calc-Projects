#!/bin/sh

if [ $# -eq 0 ]; then
    echo "Usage: ./local_tester.sh <project_folder>"
    exit -1
fi

PROJ=$1

echo "Start clang-tidy Check"
echo "No output here is good"
echo "Ignore \"database\" erorrs for now"
find ${PROJ}/ -iname "*.c" -o -iname "*.h" | xargs -I {} clang-tidy {} "-checks=-*,clang-analyzer-*,-clang-analyzer-cplusplus*,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling*,-llvmlibc-restrict-system-libc-headers" -- -I${PROJ}/hdrs 2>&1 | tee clanglog.txt
export warnings=$(grep -c warning clanglog.txt)
export suppressed=$(grep -c NOLINT clanglog.txt)
echo "End clang-tidy Check"
cd $PROJ
sh ./build.sh 
if [[ 0 -ne $(( ${warnings} - ${suppressed} )) ]]; then echo "Clang-Tidy found ${warnings} warnings." && cat ../clanglog.txt && exit 1; fi
export TEST_PROJ=$(echo $PROJ | cut -c 3-)
cd ..
python3 Tests/${TEST_PROJ}Tests.py

echo "Removing Build Artifacts"
rm -rf ${PROJ}/build
rm -rf clanglog.txt