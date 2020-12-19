# https://www.hackerrank.com/challenges/matching-same-text-again-again/problem

Regex_Pattern = r'^([a-z]\w\s\W\d\D[A-Z][a-zA-Z][auoieAOUIE]\S)\1$'

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())