# https://www.hackerrank.com/challenges/py-collections-deque/problem

from collections import deque

n = int(input())
deq = deque()

for i in range(n):
    query = input().split(' ')
    command = query[0]
    if command == 'append':
        deq.append(int(query[1]))
    if command == 'appendleft':
        deq.appendleft(int(query[1]))
    if command == 'pop':
        deq.pop()
    if command == 'popleft':
        deq.popleft()

print(*deq)
