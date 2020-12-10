# https://www.hackerrank.com/challenges/py-collections-namedtuple/problem

from collections import namedtuple

n = int(input())
fields = ' '.join([field.lower() + '_' for field in input().split()])
Student = namedtuple('Student', fields)
avg_mark = 0
for i in range(0,n):
    avg_mark += int(Student(*input().split()).marks_)
print(round(avg_mark / n, 2))
