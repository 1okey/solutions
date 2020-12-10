# https://www.hackerrank.com/challenges/np-dot-and-cross/problem

import numpy

size = int(input())
arrs = []
for i in range(2):
    arrs.append(numpy.array([[int(n) for n in input().split(' ')] for i in range(size)]))
print(numpy.dot(*arrs))

