#!/bin/bash

echo "Enter the radius of the circle:"
read radius

# Calculate the area of the circle
area=$(echo "3.14159 * $radius * $radius" | bc)

# Calculate the circumference of the circle
circumference=$(echo "2 * 3.14159 * $radius" | bc)

echo "Area of the circle: $area"
echo "Circumference of the circle: $circumference"

