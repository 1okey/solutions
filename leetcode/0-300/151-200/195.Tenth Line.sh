#/bin/sh

# https://leetcode.com/problems/tenth-line/

if [[ $(cat file.txt | wc -l) -gt 9 ]] 
then
   cat file.txt | head -10 | tail -1; 
fi

# faster one-liner

tail file.txt -n +10 | head -n1