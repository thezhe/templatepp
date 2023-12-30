#!/usr/bin/env bash
# CMake build, test, and package using Ninja. Artifacts install to `./build/install`.
# See https://cmake.org/cmake/help/latest/manual/ctest.1.html#build-and-test-mode.

pip install Ninja
ctest --build-and-test . build --build-generator Ninja --build-target package --build-noclean --build-options -DCMAKE_BUILD_TYPE=Release -DCPACK_PACKAGE_DIRECTORY=install -DCPACK_VERBATIM_VARIABLES=ON -DCPACK_STRIP_FILES=ON --test-command ctest
