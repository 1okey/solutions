# https://www.hackerrank.com/challenges/matching-ending-items/problem

Regex_Pattern = r'^[a-zA-z]{0,}s$'

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())