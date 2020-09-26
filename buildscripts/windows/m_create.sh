PROJECT=$1

rm -rf project
mkdir project
cd project
if [ "${PROJECT}" = "r" ]; then
    cmake -DCMAKE_BUILD_TYPE=Release ../src
else
    cmake -DCMAKE_BUILD_TYPE=Debug ../src
fi
