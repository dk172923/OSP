#!/bin/bash

echo "Enter a number: "
read number

echo "Digits in odd positions:"
length=${#number}

for ((i=1; i<=length; i+=2)); do
    digit=${number:i-1:1}
    echo "$digit"
done

