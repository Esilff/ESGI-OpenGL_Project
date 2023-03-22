#!/bin/bash
cmake -S . -B ./build
cd build
make
source config.sh
clear
./${PROJECT_NAME}