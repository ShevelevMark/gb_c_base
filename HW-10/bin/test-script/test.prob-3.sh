#!/usr/bin/bash

echo "Test 1: "
echo "aaa/bbb/ccc.ddd" > in.txt && ./bin/prob-3
if [[ 0 -eq $? ]]
then
    ex="aaa/bbb/ccc.html"
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
echo "aaa/bbb.txt/ccc.ddd" > in.txt && ./bin/prob-3
if [[ 0 -eq $? ]]
then
    ex="aaa/bbb.txt/ccc.html"
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
echo "aaa.bbb/bbb.txt/ccc" > in.txt && ./bin/prob-3
if [[ 0 -eq $? ]]
then
    ex="aaa.bbb/bbb.txt/ccc.html"
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

echo "Test 4: "
echo "aaa/bbb.txt/ccc.ddd.eee.ccc.999" > in.txt && ./bin/prob-3
if [[ 0 -eq $? ]]
then
    ex="aaa/bbb.txt/ccc.ddd.eee.ccc.html"
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