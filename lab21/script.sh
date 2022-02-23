#!/bin/bash
start=$(pwd)
#get derictory for check
dir=$1

var="?"
#check is parametr empty
if [ -z $dir ]
then
dir=$start
else
#manual
if [ $dir = $var ]
then
echo "Put paramter like this: source script.sh {directory}"
exit
fi
fi

count=0
cd $dir

check() {
#read ls
array=($(ls -d $PWD/*))

for file in $array
do
#if file directory
if [ -d $file ]
then
cd $file
check
else
#if file program
if [ -x $file ]
then
let count=$count+1
echo $file
fi
fi
cd ..
done
}

check
cd $start
echo Total count of programs files $count
