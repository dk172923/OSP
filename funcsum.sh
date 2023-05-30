#!/bin/bash

# Define a function to calculate the sum of two numbers
sum() {
    echo $(($1 + $2))
}

# Prompt the user to enter two numbers
echo "Enter the first number: "
read num1
echo "Enter the second number: "
read num2

# Call the sum function and store the result
result=$(sum $num1 $num2)

# Print the result
echo "The sum of $num1 and $num2 is: $result"

