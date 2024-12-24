#!/bin/bash

[ $# -eq 2 ] || { 
    echo "Usage: $(basename $0) program_name opt"
    echo "opt:"
    echo "  s  # sample dataset"
    echo "  v  # validation dataset"
    echo "  vv # actual dataset"
    echo "  f  # compare output with actual dataset"
    echo "  c  # individual datasets"
    exit 1
}

FLAGS='-std=c++17'

if [ $2 == "s" ]; then
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
elif [ $2 == "vv" ]; then
    if [ ! -f ${1}_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_input.txt | tee ${1}_out.txt
elif [ $2 == "f" ]; then
    if [ ! -f ${1}_input.txt ]; then
        echo "input?"
        exit 2;
    fi

    if [ ! -f ${1}_out.txt ]; then
        echo "original out?"
        exit 3;
    fi

    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_input.txt | tee ${1}_out2.txt && \
    if diff ${1}_out.txt ${1}_out2.txt; then
	echo "identical"
    fi
    rm -f ${1}_out2.txt
elif [ $2 == "c" ]; then
    make CPPFLAGS=${FLAGS} $1  && \
    ls ${1}* | grep -E '[0-9]{15}_input' | while read fn; do
        echo $fn 
        (echo 1; cat $fn;) | ./${1}
    done
fi


rm -f $1 
