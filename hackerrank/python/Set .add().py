# https://www.hackerrank.com/challenges/py-set-add/problem

n = int(input())
countries = set()
for i in range(0, n):
    countries.add(input())
print(len(countries))
