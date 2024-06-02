a=(1 2 3 4)
echo ${a[0]}
a[2]=5
echo ${a[2]}

a+=(7)
echo ${a[@]}
unset a[3]
echo ${a[@]}

for i in "${a[@]}"; do
echo  $i
done
