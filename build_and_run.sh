#!/bin/bash

set -e

echo "Compiling..."
make

BIN="./bin"

if [ -f "$BIN" ]; then
    echo "Executing $BIN..."
    echo ""
    $BIN
else
    echo "Binary $BIN not found."
    exit 1
fi
