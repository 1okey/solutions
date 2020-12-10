# https://www.hackerrank.com/challenges/np-min-and-max/problem

import numpy

n, m = [int(n) for n in input().split(' ')]
narr = numpy.array([[int(j) for j in input().split(' ')] for _ in range(n)])
print(numpy.max(numpy.min(narr, axis=1)))
