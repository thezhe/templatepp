#!/usr/bin/env bash

cmake -B ./build -DCMAKE_INSTALL_PREFIX=./build/install -DCMAKE_BUILD_TYPE=Release
cmake --build ./build
ctest --test-dir ./build
cmake --install ./build --strip
