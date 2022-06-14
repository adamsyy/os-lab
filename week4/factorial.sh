#!/bin/sh

echo "enter a number"
read number
//find the fctorial of the number
factorial=1
while [ $number -gt 0 ]
do
    factorial=$((factorial*number))
    number=$((number-1))
done
echo "factorial of the number is $factorial"
