echo Enter main string:
read main
l1=${#main}
echo Enter sub string:
read sub
l2=${#sub}
n=1
m=1
pos=0
while [ $n -le $l1 ]
do
a=`echo $main|cut -c $n`
b=`echo $sub|cut -c $m`
if [ $a = $b ]
then
n=`expr $n + 1`
m=`expr $m + 1`
pos=`expr $n - $l2`
r=`expr $m - 1`
if [ $r -eq $l2 ]
then
break
fi
else
pos=0
m=1
n=`expr $n + 1`
fi
done
echo Position of sub string in main string is $pos