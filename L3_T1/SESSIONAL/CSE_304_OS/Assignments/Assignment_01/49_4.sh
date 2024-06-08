echo "Number "
read x
read y

read z

case "$z" in 
	add) echo $((x+y));;
	sub) echo $((x-y));;
	mul) echo $((x*y));;
	div) echo $((x/y));;
	*) echo "Invalid";;
esac


# 202214049 Nahul

