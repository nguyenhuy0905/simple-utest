#!/bin/bash

# foolproof
make test OPTS=--debug
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:./lib/
./test/test-something
