# https://www.hackerrank.com/challenges/py-the-captains-room/problem

n = int(input())
rooms = list(map(int, input().split(' ')))
distinct = list(set(rooms))
for r in distinct:
    rooms.remove(r)
    if r not in rooms:
        print(r)
        break;

