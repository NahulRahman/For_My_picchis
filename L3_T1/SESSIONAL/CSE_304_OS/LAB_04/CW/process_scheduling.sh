#!/bin/bash
arrival_array=(0 1 2)
burst_array=(4 3 1)
complete_array=()
tat_array=()
wt_array=()
complete_array[0]=$((${arrival_array[0]}+${burst_array[0]}))
len=${#arrival_array[@]}

for ((i=1;i<$len;i++))do
    complete_array[$i]=$((${complete_array[$i-1]}+${burst_array[i]}))
done
echo "Complete Array"
for value in "${complete_array[@]}";do
    echo $value
done

for ((i=0;i<$len;i++));do
    tat_array[$i]=$((${complete_array[$i]}-${arrival_array[$i]}))
done
echo "Tat Array"
for value in "${tat_array[@]}";do
    echo $value
done
for ((i=0;i<$len;i++));do
    wt_array[$i]=$((${tat_array[$i]}-${burst_array[$i]}))
done
echo "Waiting array"
for value in "${wt_array[@]}";do
    echo $value
done
