# https://www.hackerrank.com/challenges/itertools-combinations/problem

from itertools import combinations

word, n = input().split(' ')
for i in range(int(n)):
    combos = []
    for c in combinations(word, i + 1):
        combo = list(c)
        combo.sort()
        combos.append(''.join(combo))
    
    combos.sort()
    print(*combos, sep='\n')
