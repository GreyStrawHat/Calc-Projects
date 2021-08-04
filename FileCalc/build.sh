#!/bin/bash

[ -e build ] || mkdir build
cd build
cmake ..
make
