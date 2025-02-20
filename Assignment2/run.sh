#!/bin/bash

# Define paths
EXEC="./parser"
TEST_DIR="./test"
OUTPUT_DIR="./output"

# Create output directory if not exists
mkdir -p $OUTPUT_DIR

# Run parser on each test file and store output separately
counter=1
for testfile in $TEST_DIR/*.c; do
    output_file="$OUTPUT_DIR/output${counter}.txt"
    echo "Processing $(basename "$testfile") -> $(basename "$output_file")"
    $EXEC "$testfile" > "$output_file"
    ((counter++))
done

echo "All test cases executed. Outputs stored in $OUTPUT_DIR."
