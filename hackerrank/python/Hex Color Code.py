# https://www.hackerrank.com/challenges/hex-color-code/problem

import re
n = int(input())

regex = re.compile(r'(?<!^)(#[a-fA-f\d]{3,6})')
for i in range(n):
    match = regex.findall(input())
    if match:
        print(*match, sep='\n')
