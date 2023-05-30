echo "Enter a number"
read n
echo "Even Numbers:  "
i=1
while [ $i -le $n ]   
do  
	rs=`expr $i % 2`
if [ $rs == 0 ]
then
	echo "  $i"
fi
((++i)) 
done
echo "Odd Numbers:  "
i=1  
while [ $i -le $n ]
do  
	rs=`expr $i % 2`
if [ $rs != 0 ]
then
	echo "  $i"  
fi
((++i))
done
