# https://www.hackerrank.com/challenges/collections-counter/problem

from collections import Counter

n_pairs = int(input())
shoes = Counter([int(n) for n in input().split(' ')])
customers = int(input())
income = 0
for c in range(0,customers):
    size, money = [int(n) for n in input().split(' ')]
    if shoes[size] > 0:
        income += money
        shoes[size] -= 1

print(income)
