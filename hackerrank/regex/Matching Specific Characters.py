# https://www.hackerrank.com/challenges/matching-specific-characters/problem

Regex_Pattern = r'^[1-3][0-2][x|s|0][0|3|a|A][x|s|u][\.\,]$'

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())