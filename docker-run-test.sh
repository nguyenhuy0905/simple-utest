#!/bin/bash

# this script is meant to be executed inside the Docker container
make
make test > output.txt.format
