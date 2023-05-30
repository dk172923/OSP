#!/bin/bash

echo "Enter a value: "
read a
echo "Enter b value: "
read b
echo "Enter c value: "
read c

x1=$(echo "scale=7; (-$b+sqrt($b^2-4*$a*$c))/(2*$a)" | bc)
x2=$(echo "scale=7; (-$b-sqrt($b^2-4*$a*$c))/(2*$a)" | bc)

echo "Root 1: $x1"
echo "Root 2: $x2"

