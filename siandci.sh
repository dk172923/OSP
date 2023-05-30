#!/bin/bash

# Function to calculate simple interest
calculate_simple_interest() {
    principal=$1
    rate=$2
    time=$3

    # Simple Interest formula: SI = (P * R * T) / 100
    si=$(( (principal * rate * time) / 100 ))

    echo "Simple Interest: $si"
}

# Function to calculate compound interest
calculate_compound_interest() {
    principal=$1
    rate=$2
    time=$3

    # Compound Interest formula: CI = P * (1 + R/100)^T - P
    ci=$(echo "$principal * (1 + $rate/100)^$time - $principal" | bc)

    echo "Compound Interest: $ci"
}

echo "Enter principal amount:"
read principal

echo "Enter interest rate:"
read rate

echo "Enter time period (in years):"
read time

echo "Calculating interest..."
calculate_simple_interest $principal $rate $time
calculate_compound_interest $principal $rate $time

