# https://www.hackerrank.com/challenges/defaultdict-tutorial/problem

from collections import defaultdict
m, n = [int(n) for n in input().split(' ')]
dict1 = defaultdict(list)
for i in range(0,m):
    dict1[input()].append(i + 1)

for i in range(0,n):
    occurences = dict1[input()]
    if len(occurences) > 0:
        print(*occurences)
    else:
        print(-1)
