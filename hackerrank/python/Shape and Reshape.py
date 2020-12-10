# https://www.hackerrank.com/challenges/np-shape-reshape/problem

import numpy

narr = numpy.array([int(n) for n in input().split(' ')]) 
print(numpy.reshape(narr, (3,3)))
