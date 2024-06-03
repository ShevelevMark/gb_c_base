#!/usr/bin/bash

echo "Test 1: "
echo "a ab abu abba baba abi ba b" > in.txt && ./bin/prob-5
if [[ 0 -eq $? ]]
then  
    ex="abba"
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
echo "abbacus acme abba alas" > in.txt && ./bin/prob-5
if [[ 0 -eq $? ]]
then  
    ex="abbacus"
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
echo "acme abba alas abbacus" > in.txt && ./bin/prob-5
if [[ 0 -eq $? ]]
then  
    ex="abbacus"
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

echo "Test 4: "
echo "   acme    abba     alas  abbacus tarantul  mangusu   " > in.txt && ./bin/prob-5
if [[ 0 -eq $? ]]
then  
    ex="tarantul"
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