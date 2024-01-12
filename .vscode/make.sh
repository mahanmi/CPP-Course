#!/bin/bash
cd /Users/mahan/Documents/VS\ Code/C++/SDL
src=$(echo "$1" | sed 's/\/Users\/mahan\/Documents\/VS Code\/C++\/SDL\///')
file_name="$2"
make SRC_DIR="$src" FILE_NAME="$file_name"
