#!/bin/bash

bb_build () {

    dir="$(dirname "$(readlink -f "$0")")"
    # Get name of file to compile
    name=$(basename $dir)

    IFS='-'
    set -o noglob
    field=($name) # split+glob  operator
    name=${field[-1]}

    target="$name$(echo "$1" | tr -d ' ')"

    mkdir -p "$(dirname "$0")/build"

    echo "Building $target ..."
    gcc -o "$dir/build/bb-$target" "$dir/$name.c" $1

}


build () {

    # Get name of file to compile

    dir="$(dirname "$(readlink -f "$0")")"
    
    name=$(basename $dir)

    IFS='-'
    set -o noglob
    field=($name) # split+glob  operator
    name=${field[-1]}

    echo $name

    target="$name$(echo "$2" | tr -d ' ')"

    mkdir -p "$dir/build"

    echo "Building $target ..."

    afl-gcc -o "$dir/build/$target" "$dir/harness.c" $2

}

"$@"