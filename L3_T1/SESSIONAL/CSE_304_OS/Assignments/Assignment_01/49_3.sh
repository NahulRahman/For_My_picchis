#factorial code

echo "Enter number"
read n
f=1
for ((i=2;i<=n;i++))
 
do
	f=$((f * i))
done

echo $((f))
