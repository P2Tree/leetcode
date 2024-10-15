#!/usr/bin/env bash

set -e

echo "building..."
# g++ $1 --std=c++17 -g -o test
clang++ $1 --std=c++17 -g -o test

echo "running..."
./test
