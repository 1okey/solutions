# https://www.hackerrank.com/challenges/matching-word-boundaries/problem

Regex_Pattern = r'\b[aeuioAUIOE][a-z]*\b'

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())