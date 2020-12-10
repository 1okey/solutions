# https://www.hackerrank.com/challenges/py-check-subset/problem

n = int(input())
for _ in range(0,n):
    m = input()
    set_a = set(map(int, input().split(' ')))
    n = input()
    set_b = set(map(int, input().split(' ')))
    
    print(set_a.issubset(set_b))
