# https://www.hackerrank.com/challenges/py-set-discard-remove-pop/problem

from functools import reduce
n = int(input())
s = set(map(int, input().split()))
m = int(input())
for i in range(0, m):
    query = input().split(' ')
    command = query.pop(0)
    if command == "pop":
        s.pop()
    if command == "remove":
        item = int(query.pop())
        try:
            s.remove(item)
        except:
            continue
    if command == "discard":
        item = int(query.pop())
        s.discard(item)
print(reduce(lambda a,b : a + b, list(s), 0))
