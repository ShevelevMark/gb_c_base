#!/usr/bin/bash

echo "Test 1: "
echo "data 48 call 9 read13 blank0a" > in.txt && ./bin/prob-3
if [[ 0 -eq $? ]]
then  
    ex="0 9 13 48 "
    ac=$(cat out.txt)
    if [[ "${ac}" == "${ex}" ]]
    then
        echo "OK"
    else
        echo "FAIL"
        echo "${ac};${ex}"
        exit 1
    fi
fi

echo "Test 2: "
echo "4567" > in.txt && ./bin/prob-3
if [[ 0 -eq $? ]]
then  
    ex="4567 "
    ac=$(cat out.txt)
    if [[ "${ac}" == "${ex}" ]]
    then
        echo "OK"
    else
        echo "FAIL"
        echo "${ac};${ex}"
        exit 1
    fi
fi

echo "Test 3: "
echo "-1caramba -3 hello0ka bambuk-5" > in.txt && ./bin/prob-3
if [[ 0 -eq $? ]]
then  
    ex="-5 -3 -1 0 "
    ac=$(cat out.txt)
    if [[ "${ac}" == "${ex}" ]]
    then
        echo "OK"
    else
        echo "FAIL"
        echo "${ac};${ex}"
        exit 1
    fi
fi