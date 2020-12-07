# https://www.hackerrank.com/challenges/matching-start-end/problem

Regex_Pattern = r"^\d{1}\w{4}.$"

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())