# https://www.hackerrank.com/challenges/itertools-combinations-with-replacement/problem

from itertools import combinations_with_replacement

word, size = input().split(' ')

combos = []
for c in combinations_with_replacement(word, int(size)):
    c = list(c)
    c.sort()
    c_str = ''.join(c)
    combos.append(c_str)

combos.sort()
print(*combos, sep='\n')
