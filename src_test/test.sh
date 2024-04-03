#!/bin/bash

make clean
make

if [ -d "test" ]; then
    rm -rf test
fi

if [ -d "res" ]; then
    rm -rf res
fi
rm test.txt

mkdir test
cp -r const/folder const/file const/toCopy.txt const/toMove.txt const/toRemove.txt  test/
mkdir res
touch test.txt

echo "cd test" > instructions.txt 
echo "pwd" >> instructions.txt 
echo "cd .." >> instructions.txt
echo "cp test/toCopy.txt res/copied.txt" >> instructions.txt
echo "ls res" >> instructions.txt
echo "mv test/toMove.txt res/moved.txt" >> instructions.txt
echo "ls res" >> instructions.txt
echo "delete test/toRemove.txt" >> instructions.txt
echo "ls test" >> instructions.txt
echo "read test/file" >> instructions.txt
echo "read test/file | grep word" >> instructions.txt
echo "echo \"Hello World\" > res/h.txt" >> instructions.txt
echo "read res/h.txt" >> instructions.txt
echo "exit testing" >> instructions.txt

./build/program < instructions.txt > test.txt
rm instructions.txt