# https://www.hackerrank.com/challenges/itertools-permutations/problem

from itertools import permutations
word, n = input().split(' ')
perms = list([''.join(t) for t in permutations(word, int(n))])
perms.sort()
print(*perms, sep='\n')
