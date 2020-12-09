# https://www.hackerrank.com/challenges/bash-tutorials---getting-started-with-conditionals/problem

read l

if [[ "$l" == ['yY'] ]]
then
    echo "YES"
else
    echo "NO"
fi