#!/usr/bin/env bash

pip install Ninja
cmake -B ./build -DCMAKE_INSTALL_PREFIX=./build/install -DCMAKE_BUILD_TYPE=Release -G Ninja
cmake --build ./build
ctest --test-dir ./build
cmake --install ./build --strip
