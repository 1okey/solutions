# https://www.hackerrank.com/challenges/validating-the-phone-number/prolem

import re

n = int(input())

for i in range(n):
    print('YES' if re.search('^[789]{1}\d{9}$', input()) != None else 'NO')
