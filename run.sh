#!/usr/bin/env bash

echo "building..."
g++ $1 --std=c++17 -g -o test

echo "running..."
./test
