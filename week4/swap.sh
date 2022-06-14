#!/bin/sh

echo "enter number 1"
read num1
echo "enter number 2"
read num2
echo "before swapping: num1 = $num1, num2 = $num2"
temp=$num1
num1=$num2
num2=$temp
echo "after swapping: num1 = $num1, num2 = $num2"