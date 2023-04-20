#!/bin/bash
rm -dr build
mkdir build
cmake -S . -B ./build
cd build
make
source config.sh
if [ "$1" != '--debug' ]; then
    clear
fi
./${PROJECT_NAME}