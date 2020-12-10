# https://www.hackerrank.com/challenges/itertools-product/problem

from itertools import product

a = [int(n) for n in input().split(' ')]
b = [int(n) for n in input().split(' ')]

print(*product(*[a,b]))
