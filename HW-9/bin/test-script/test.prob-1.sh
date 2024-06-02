#!/usr/bin/bash

echo "Test 1: "
echo "hello world" > in.txt && ./bin/prob-1
if [[ 0 -eq $? ]]
then  
    ex="o "
    ac=$(cat out.txt)
    if [[ "${ac}" == "${ex}" ]]
    then
        echo "OK"
    else
        echo "FAIL"
        exit 1
    fi
fi

echo "Test 2: "
echo "abcd bdeaa" > in.txt && ./bin/prob-1
if [[ 0 -eq $? ]]
then
    ex="b d "
    ac=$(cat out.txt)
    if [[ ${ac} == ${ex} ]]
    then 
        echo "OK"
    else
        echo "FAIL"
        exit 1
    fi
fi

echo "Test 3: "
echo "abracadabra caramba" > in.txt && ./bin/prob-1
if [[ 0 -eq $? ]]
then  
    ex="c "
    ac=$(cat out.txt)
    if [[ "${ac}" == "${ex}" ]]
    then
        echo "OK"
    else
        echo "FAIL"
        exit 1
    fi
fi