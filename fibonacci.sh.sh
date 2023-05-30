#!/bin/bash

# Prompt the user for the number of terms in the Fibonacci series
echo "Enter the number of terms in the Fibonacci series:"
read num_terms

# Initialize the first two terms
term1=0
term2=1

echo "Fibonacci series for $num_terms terms:"

# Check if the number of terms is 0
if [ $num_terms -gt 0 ]; then
    echo -n "$term1 " # Print the first term

    # Iterate from 2nd term to the desired number of terms
    for ((i=2; i<=num_terms; i++)); do
        echo -n "$term2 " # Print the current term
        next=$((term1 + term2))
        term1=$term2
        term2=$next
    done
fi

echo # Print a new line after the series

