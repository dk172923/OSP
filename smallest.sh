#!/bin/bash

# Prompt the user to enter a number
read -p "Enter a number: " number

# Initialize the smallest variable with the first digit of the number
smallest=${number:0:1}

# Iterate through each digit of the number
for (( i=1; i<${#number}; i++ )); do
    digit=${number:i:1}

    # Compare the current digit with the smallest digit
    if (( digit < smallest )); then
        smallest=$digit
    fi
done

# Display the smallest digit
echo "The smallest digit in the number is: $smallest"

