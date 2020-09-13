if [ "$1" == "d" ]; then
    ./project/Debug/codejam
elif [ "$1" == "r" ]; then
    ./project/Release/codejam
else
    ./project/codejam
fi