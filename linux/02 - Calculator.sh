echo MENU BASED MATH CALCULATOR
echo Enter the operands
read a
read b
echo Enter the operator
read o
case $o in
    "+") echo "$a + $b = `expr $a + $b`";;
    "-") echo "$a - $b = `expr $a - $b`";;
    "*") echo "$a * $b = `expr $a \* $b`";;
    "/") echo "$a / $b = `expr $a / $b`";;
    *) echo "INVALID OPERATOR"
esac