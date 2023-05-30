echo "Enter a string 1 " 
read first
echo "Enter a string 2 "
read second
if [ $first = $second ]	# this “ =” for other than digits equals then
then 
		echo "Strings are equal"
else
		echo "Strings are not equal"
fi
