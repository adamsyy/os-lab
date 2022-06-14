#!/bin/sh

echo "enter number"
read num

if [ `expr $num % 2` -eq 0 ]
then
    echo "even"
else
    echo "odd"
fi