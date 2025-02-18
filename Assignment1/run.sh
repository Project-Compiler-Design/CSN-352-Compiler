#!/bin/bash

# Define paths
EXEC="./lexer"
TEST_DIR="./test"
OUTPUT_DIR="./output"

# Create output directory if not exists
mkdir -p $OUTPUT_DIR

# Run lexer on each test file and store output separately
counter=1
for testfile in $TEST_DIR/*.c; do
    output_file="$OUTPUT_DIR/output${counter}.txt"
    echo "Processing $(basename "$testfile") -> $(basename "$output_file")"
    $EXEC "$testfile" "$output_file"  # Pass input and output files as arguments
    ((counter++))
done

echo "All test cases executed. Outputs stored in $OUTPUT_DIR."
