#!/bin/bash

[ $# -eq 2 ] || { echo "$0 prog no."; exit 1; }

if [ $2 == "s" ]; then
    if [ ! -f ${1}_sample_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make $1  && \
    ./$1 < ${1}_sample_input.txt
elif [ $2 == "v" ]; then
    if [ ! -f ${1}_validation_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make $1  && \
    ./$1 < ${1}_validation_input.txt | tee ${1}_validation_out.txt 
elif [ $2 == "vv" ]; then
    if [ ! -f ${1}_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make $1  && \
    ./$1 < ${1}_input.txt | tee ${1}_out.txt 
elif [ $2 == "c" ]; then
    make $1  && \
    ls ${1}* | grep -E '[0-9]{2,}' | while read fn; do
        echo $fn 
        (echo 1; cat $fn;) | ./${1}
    done
fi


rm $1 
