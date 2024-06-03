#!/usr/bin/bash

echo "Test 1: "
echo "Mama mila ramu" > in.txt && ./bin/prob-6
if [[ 0 -eq $? ]]
then  
    ex="2"
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
echo "A" > in.txt && ./bin/prob-6
if [[ 0 -eq $? ]]
then  
    ex="1"
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
echo "Abraham alard mudarah" > in.txt && ./bin/prob-6
if [[ 0 -eq $? ]]
then  
    ex="0"
    ac=$(cat out.txt)
    if [[ "${ac}" == "${ex}" ]]
    then
        echo "OK"
    else
        echo "FAIL"
        exit 1
    fi
fi

echo "Test 4: "
echo "Raban Muaddib Pola " > in.txt && ./bin/prob-6
if [[ 0 -eq $? ]]
then  
    ex="1"
    ac=$(cat out.txt)
    if [[ "${ac}" == "${ex}" ]]
    then
        echo "OK"
    else
        echo "FAIL"
        exit 1
    fi
fi

echo "Test 5: "
echo " This   is a    string with   unxpectedly  many spaces, Ada  " > in.txt && ./bin/prob-6
if [[ 0 -eq $? ]]
then  
    ex="2"
    ac=$(cat out.txt)
    if [[ "${ac}" == "${ex}" ]]
    then
        echo "OK"
    else
        echo "FAIL"
        exit 1
    fi
fi