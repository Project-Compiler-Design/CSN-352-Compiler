#!/bin/bash
# run.sh: Process all *.c files in the test folder using the parser

# Build the parser
make

# Create output directory if it doesn't exist
mkdir -p output

# Loop over each .c file in the test folder
for file in test/*.c; do
    base=$(basename "$file")
    output="output/${base}.out"
    echo "Processing $file -> $output"
    ./parser "$file" "$output"
done
