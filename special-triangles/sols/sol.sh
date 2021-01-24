g=0

gcd () {
    if [ "$2" -ne 0 ]
    then
        gcd "$2" "$(($1 % $2))"
    else
        g="$1"
    fi
}

read a b

gcd $a $b

a="$(($a / $g))"
b="$(($b / $g))"

if [ "$b" -gt 2 ]
then
    echo -1
else
    if [ "$b" -eq 1 ]
    then
        a="$(($a * 2))"
    fi
    echo 1
    echo 0 "$(($a * 2))" 2 $a 3 0
fi
