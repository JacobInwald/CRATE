#!/bin/bash

bb_build () {

    # Get name of file to compile
    name=$(basename $(dirname "$0"))

    IFS='-'
    set -o noglob
    field=($name) # split+glob  operator
    name=${field[-1]}

    target="$name$(echo "$1" | tr -d ' ')"

    mkdir -p "$(dirname "$0")/build"

    echo "Building $target ..."
    gcc -o "$(dirname "$0")/build/$target" "$(dirname "$0")/$name.c" $1

}

build () {

    # Get name of file to compile
    name=$(basename $(dirname "$0"))

    IFS='-'
    set -o noglob
    field=($name) # split+glob  operator
    name=${field[-1]}

    target="$name$(echo "$1" | tr -d ' ')"

    mkdir -p "$(dirname "$0")/build"

    echo "Building $target ..."

    afl-clang-fast -o "$(dirname "$0")/build/$target" "$(dirname "$0")/harness.c" -l$name $1

}

"$@"