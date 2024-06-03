#!/usr/bin/bash

echo "Test 1: "
echo "abc cde def" > in.txt && ./bin/prob-4
if [[ 0 -eq $? ]]
then  
    ex="abcdef"
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
echo "  Abra mabra cadabra!  Mamma mia! Oh, didn't notice you...  Xander, hello! " > in.txt && ./bin/prob-4
if [[ 0 -eq $? ]]
then  
    ex="Abramcd!MiOh,n'toeyu.Xl"
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
echo "1234567890qwertyuiopasdfghjklzxcvbnm.,;:|+-!" > in.txt && ./bin/prob-4
if [[ 0 -eq $? ]]
then  
    ex="1234567890qwertyuiopasdfghjklzxcvbnm.,;:|+-!"
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
echo "            " > in.txt && ./bin/prob-4
if [[ 0 -eq $? ]]
then  
    ex=""
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