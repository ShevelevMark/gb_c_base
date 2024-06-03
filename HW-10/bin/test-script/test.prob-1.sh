#!/usr/bin/bash

echo "Test 1: "
echo "Hello world!" > in.txt && ./bin/prob-1
if [[ 0 -eq $? ]]
then
    ex="eHllw orodl!"
    ac=$(cat out.txt)
    if [[ ${ac} == ${ex} ]]
    then
        echo "OK"
    else
        echo "FAIL"
        echo "ex:${ex}; ac:${ac}"
        exit 1;
    fi
fi

echo "Test 2: "
echo "a" > in.txt && ./bin/prob-1
if [[ 0 -eq $? ]]
then
    ex="a"
    ac=$(cat out.txt)
    if [[ ${ac} == ${ex} ]]
    then
        echo "OK"
    else
        echo "FAIL"
        echo "ex:${ex}; ac:${ac}"
        exit 1;
    fi
fi

echo "Test 3: "
echo "             " > in.txt && ./bin/prob-1
if [[ 0 -eq $? ]]
then
    ex="             "
    ac=$(cat out.txt)
    if [[ ${ac} == ${ex} ]]
    then
        echo "OK"
    else
        echo "FAIL"
        echo "ex:${ex}; ac:${ac};"
        exit 1;
    fi
fi

echo "Test 4: "
echo "$             ^" > in.txt && ./bin/prob-1
if [[ 0 -eq $? ]]
then
    ex="^             $"
    ac=$(cat out.txt)
    if [[ ${ac} == ${ex} ]]
    then
        echo "OK"
    else
        echo "FAIL"
        echo "ex:${ex}; ac:${ac};"
        exit 1;
    fi
fi