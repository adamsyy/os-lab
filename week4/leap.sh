#!/bin/sh

echo "enter year"
read year
//check if year is leap 
if [ $((year%4)) -eq 0 ]
then
    if [ $((year%100)) -eq 0 ]
    then
        if [ $((year%400)) -eq 0 ]
        then
            echo "leap year"
        else
            echo "not a leap year"
        fi
    else
        echo "leap year"
    fi
else
    echo "not a leap year"
fi
