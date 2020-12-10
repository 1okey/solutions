# https://www.hackerrank.com/challenges/py-set-mutations/problem

from functools import reduce

m = int(input())
a = set(map(int, input().split(' ')))
m = int(input())
for n in range(0,m):
    query = input().split(' ')
    command = query.pop(0)
    b = set(map(int, input().split(' ')))

    if command == 'intersection_update':
        a &= b
    if command == 'update':
        a |= b
    if command == 'difference_update':
        a -= b
    if command == 'symmetric_difference_update':
        a ^= b

print(reduce(lambda a,b: a + b, list(a), 0))
