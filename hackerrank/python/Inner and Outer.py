# https://www.hackerrank.com/challenges/np-inner-and-outer/problem

import numpy

arrs = [[numpy.array(n) for n in map(int,input().split(' '))] for i in range(2)]
print(numpy.inner(*arrs), numpy.outer(*arrs), sep='\n')

