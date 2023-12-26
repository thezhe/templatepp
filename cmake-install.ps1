#!/usr/bin/env bash

cmake -B ./build -DCMAKE_INSTALL_PREFIX=./build/install -DCMAKE_BUILD_TYPE=Release
cmake --build ./build --config Release
ctest --test-dir ./build -C Release
cmake --install ./build --config Release --strip
