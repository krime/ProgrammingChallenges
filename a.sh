#!/bin/bash

declare -a arr=({0..51})
function Swap() {
    t=${arr[$1]};
    arr[$1]=${arr[$2]};
    arr[$2]=$t;
}
function Flush() {
    for i in {51..1}; do
        k=$(($RANDOM % $i))
        Swap $i $k
    done
}
function Card() {
    r=$(($1%13));
    s=$(($1/13));
    case $s in
        0) suit=H;;
        1) suit=D;;
        2) suit=C;;
        3) suit=S;;
    esac
    case $r in
        [0-7]) rank=$((2+$r));;
        8) rank=T;;
        9) rank=J;;
        10) rank=Q;;
        11) rank=K;;
        12) rank=A;;
    esac
    echo -n "$rank$suit "
}
function Cards() {
    for i in {0..9}; do
        Card ${arr[$i]}
    done
}
Flush
Cards
echo -e "\006"
# echo ${arr[*]}
