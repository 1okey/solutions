# https://www.hackerrank.com/challenges/np-concatenate/problem

import numpy

n,m,p = [int(n) for n in input().split(' ')]
print(numpy.array([[int(i) for i in input().split(' ')] for i in range(0, n + m)]))
