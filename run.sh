#!/bin/bash

set -e

mkdir -p build
echo "Compiling..."
cd build
cmake ..
make
cd ..

BIN="build/emb-c-design-patterns"

if [ -f "$BIN" ]; then
    echo "Executing $BIN..."
    echo ""
    $BIN
else
    echo "Binary $BIN not found."
    exit 1
fi
