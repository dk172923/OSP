#!/bin/bash

echo "Enter a line of text:"
read text

# Convert the text to lowercase for case-insensitive matching
text_lower=$(echo "$text" | tr '[:upper:]' '[:lower:]')

# Count the number of vowels
vowel_count=$(echo "$text_lower" | grep -o -E '[aeiou]' | wc -l)

echo "Number of vowels: $vowel_count"

