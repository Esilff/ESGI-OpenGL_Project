#!/bin/bash
cmake -S . -B ./build
cd build
make
source config.sh
if [ "$1" != '--debug' ]; then
    clear
fi
./${PROJECT_NAME}
echo $1