#!/bin/sh

rm -f build/* compile_commands.json

mkdir -p build && cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G Ninja -DCMAKE_BUILD_TYPE=Debug -DTEST_SIMPLE_UTEST=ON ..
cd ..
ln -s ./build/compile_commands.json compile_commands.json
cmake --build build
./test-simple-utest
