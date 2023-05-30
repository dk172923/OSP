#!/bin/bash

echo "Enter student name:"
read name

echo "Enter student score:"
read score

grade=""

if ((score >= 90)); then
    grade="A"
elif ((score >= 80)); then
    grade="B"
elif ((score >= 70)); then
    grade="C"
elif ((score >= 60)); then
    grade="D"
else
    grade="F"
fi

echo "Student Name: $name"
echo "Student Score: $score"
echo "Grade: $grade"

