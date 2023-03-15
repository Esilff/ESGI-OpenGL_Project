#!/bin/bash
cmake -S . -B ./build
cd build
make
source config.sh
./${PROJECT_NAME}