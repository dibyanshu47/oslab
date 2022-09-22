echo Enter the limit
read n
echo PATTERN
i=1
while [ $i -le $n ]
do
j=1
while [ $j -le $i ]
do
echo -n "$"
j=`expr $j + 1`
done
echo ""
i=`expr $i + 1`
done