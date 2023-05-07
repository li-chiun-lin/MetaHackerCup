#!/bin/bash

[ $# -eq 2 ] || { echo "$0 type?"; exit 1; }

FLAGS='-std=c++17'

if [ $2 == "s" ]; then
    if [ ! -f ${1}_sample_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_sample_input.txt > ${1}_sample_out.txt  && \
    diff ${1}_sample_output.txt ${1}_sample_out.txt         

    rm -f ${1}_sample_out.txt


elif [ $2 == "sd" ]; then
    if [ ! -f ${1}_sample_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_sample_input.txt 


elif [ $2 == "v" ]; then
    if [ ! -f ${1}_validation_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_validation_input.txt | tee ${1}_validation_out.txt


elif [ $2 == "c" ]; then

    make CPPFLAGS=${FLAGS} $1  && \
    for match in "${1}_[0-9]*_input.txt"; do
        echo $match | sed 's/\ /\n/g' | while read fn; do
            echo $fn;
            ./$1 < $fn;
        done
    done

elif [ $2 == "f" ]; then

    if [ ! -f ${1}_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_input.txt

else
    if [ ! -f ${1}_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_input.txt > ${1}_out.txt
fi


rm -f $1 
