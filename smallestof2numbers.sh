#!/bin/bash

# Function to find the smallest number
find_smallest() {
    if (( $1 < $2 )); then
        echo $1
    else
        echo $2
    fi
}

# Prompt the user to enter two numbers
read -p "Enter the first number: " num1
read -p "Enter the second number: " num2

# Call the function and pass the two numbers as arguments
result=$(find_smallest $num1 $num2)

# Display the smallest number
echo "The smallest number is: $result"

