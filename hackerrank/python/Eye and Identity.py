# https://www.hackerrank.com/challenges/np-eye-and-identity/problem

import numpy
numpy.set_printoptions(legacy='1.13')

n, m = [int(n) for n in input().split(' ')]
print(numpy.eye(n, m, k = 0))
