# https://www.hackerrank.com/challenges/np-sum-and-prod/problem

import numpy

n, m = [int(n) for n in input().split(' ')]
narr = numpy.array([[int(j) for j in input().split(' ')] for _ in range(n)])
print(numpy.prod(numpy.sum(narr, axis=0)))
