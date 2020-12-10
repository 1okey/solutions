# https://www.hackerrank.com/challenges/np-transpose-and-flatten/problem

import numpy

n,m = [int(n) for n in input().split(' ')]
arr = [[int(n) for n in input().split(' ')] for i in range(0,n)]
np_arr = numpy.array(arr)
print(np_arr.transpose(), np_arr.flatten(), sep='\n')
