# https://www.hackerrank.com/challenges/incorrect-regex/problem

import re
for case in range(0, int(input())):
    try:
        reg = re.compile(input())
        print(True)
    except Exception as e:
        print(False)
