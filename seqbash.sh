#!/bin/bash

echo "Enter the file name: "
read file_name

echo "Enter the number of blocks to allocate: "
read num_blocks

# Create an empty file
touch "$file_name"

# Allocate blocks sequentially
for ((i=1; i<=num_blocks; i++)); do
    echo "Block $i" >> "$file_name"
done

echo "File '$file_name' created with $num_blocks blocks allocated."

