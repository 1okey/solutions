# https://www.hackerrank.com/challenges/introduction-to-regex/problem

import re
exp = re.compile('^[+-]?\d*(?!\w)\.\d+(?!\w)$')
for n in range(int(input())):
    print(exp.match(input()) != None)
