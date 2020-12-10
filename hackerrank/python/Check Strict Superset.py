# https://www.hackerrank.com/challenges/py-check-strict-superset/problem

main = set(map(int, input().split(' ')))
n = int(input())
is_superset = True
for i in range(0,n):
    set_ = set(map(int, input().split(' ')))
    if not main.issuperset(set_):
        is_superset = False
        break

print(is_superset)
