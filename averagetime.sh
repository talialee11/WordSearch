#!/bin/bash
#get user input
echo "Input dictionary file: "
read -p "" dict
echo "Input grid file: "
read -p "" grid
#run program 5 times and store values
runningtime1=`./a.out ${dict} ${grid} | tail -1`
runningtime2=`./a.out ${dict} ${grid} | tail -1`
runningtime3=`./a.out ${dict} ${grid} | tail -1`
runningtime4=`./a.out ${dict} ${grid} | tail -1`
runningtime5=`./a.out ${dict} ${grid} | tail -1`
time1=$((${runningtime1}))
time2=$((${runningtime2}))
time3=$((${runningtime3}))
time4=$((${runningtime4}))
time5=$((${runningtime5}))
#find average
time=$(((${time1} + ${time2} + ${time3} + ${time4} + ${time5})/5))
#print result
echo ${time}
					     

