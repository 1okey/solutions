# https://www.hackerrank.com/challenges/validating-named-email-addresses/problem

import re
n = int(input())

for i in range(n):
    email = input()
    if re.search('<[a-zA-Z][a-zA-Z0-9_.-]+@[a-z]+\.[a-z]{1,3}>', email):
        print(email)
