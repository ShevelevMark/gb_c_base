#!/usr/bin/bash

if [ ! $# -eq 1 ]
then
    echo "Expect exactly one argument: home word directory suffix"
    exit 1
fi

mkdir -p HW-$1/src
mkdir -p HW-$1/bin
mkdir -p HW-$1/res
cp Makefile HW-$1/Makefile
touch HW-$1/src/.hold
touch HW-$1/bin/.hold
touch HW-$1/res/.hold

