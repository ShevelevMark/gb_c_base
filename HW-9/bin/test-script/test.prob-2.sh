#!/usr/bin/bash

echo "Test 1: "
echo "aabbccddABCD" > in.txt && ./bin/prob-2
if [[ 0 -eq $? ]]
then  
    ex="bbaaccddBACD"
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
echo "AABB" > in.txt && ./bin/prob-2
if [[ 0 -eq $? ]]
then  
    ex="BBAA"
    ac=$(cat out.txt)
    if [[ "${ac}" == "${ex}" ]]
    then
        echo "OK"
    else
        echo "FAIL"
        exit 1
    fi
fi

echo "Test 3: "
echo "HeLLoWorlDXUtrenvi" > in.txt && ./bin/prob-2
if [[ 0 -eq $? ]]
then  
    ex="HeLLoWorlDXUtrenvi"
    ac=$(cat out.txt)
    if [[ "${ac}" == "${ex}" ]]
    then
        echo "OK"
    else
        echo "FAIL"
        exit 1
    fi
fi