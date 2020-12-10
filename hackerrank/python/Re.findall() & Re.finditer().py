# https://www.hackerrank.com/challenges/re-findall-re-finditer/problem

import re
consonants = '[qwrtypsdfghjklzxcvbnm]'

matches = re.findall('(?<=' + consonants +')([aeiou]{2,})' + consonants, input(), re.I)
if matches:
    print(*matches, sep='\n')
else:
    print(-1)
