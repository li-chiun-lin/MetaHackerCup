#!/bin/bash

[ $# -eq 2 ] || { echo "$0 prog no."; exit 1; }

if [ $2 == "s" ]; then
    if [ ! -f ${1}_sample_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make $1  && \
    ./$1 < ${1}_sample_input.txt | tee ${1}_sample_out.txt  && \
    diff ${1}_sample_output.txt ${1}_sample_out.txt         && \
    rm ${1}_sample_out.txt


elif [ $2 == "sd" ]; then
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


elif [ $2 == "m" ]; then
    if [ ! -f ${1}_customized_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make $1  && \
    ./$1 < ${1}_customized_input.txt > ${1}_customized_out.txt


else
    if [ ! -f ${1}_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make $1  && \
    ./$1 < ${1}_input.txt > ${1}_out.txt
fi


rm $1 
