gcc ./DN08b_63200019.c

for ((i = 0; i<= 10; i++))
do
    str=""
    if (( i != 10 )); then
        str="0"
    fi
    ./a.out < test$str$i.in > res$str$i
    if cmp --silent res$str$i test$str$i.out; then
        echo "primer[$i] pravilen" 
    else 
        echo "primer[$i] nepravilen"
        echo "My output: "
        cat res$str$i
        echo "How it should be: "
        cat test$str$i.out
        echo "\n\n\n"
    fi
    rm res$str$i
done
