#!/bin/bash

# Prompt the user to enter the temperature in Fahrenheit
read -p "Enter the temperature in Fahrenheit: " fahrenheit

# Perform the temperature conversion
celsius=$(echo "scale=2; ($fahrenheit - 32) * 5 / 9" | bc)

# Display the result
echo "The temperature in Celsius is: $celsius degrees Celsius"

