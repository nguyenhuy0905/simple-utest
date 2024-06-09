#!/bin/sh

rm -rf build compile_commands.json

mkdir -p build && cd build

cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G Ninja -DCMAKE_BUILD_TYPE=Debug ..
cd ..
ln -s ./build/compile_commands.json compile_commands.json
