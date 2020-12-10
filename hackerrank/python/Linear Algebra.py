# https://www.hackerrank.com/challenges/np-linear-algebra/problem

import numpy

m = int(input())
arr = numpy.array([[float(n) for n in input().split(' ')] for i in range(0, m)])
print(round(numpy.linalg.det(arr),2))
