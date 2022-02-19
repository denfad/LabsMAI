#!/bin/bash
#name of file
dir=$1
#Take indexes of rows, so values we must delete
indexes=($(awk -F".|=" '/url/ || /username/ || /password/ || /port/  {printf "%s ", FNR}' $dir))
awk -F"=" '/url/ || /username/ || /password/ || /port/  {print "clean row " $1}' $dir
for h in $indexes
do
sed -i '' "$h s/=.*/=/g" $dir
done

#delete coments sign before rows
sed -i '' 's/#//g' $dir
echo $dir ready for commit


