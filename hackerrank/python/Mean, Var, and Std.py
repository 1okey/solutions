# https://www.hackerrank.com/challenges/np-mean-var-and-std/problem

import numpy

numpy.set_printoptions(legacy='1.13')

n, m = [int(n) for n in input().split(' ')]
arr = numpy.array([[int(n) for n in input().split(' ')] for _ in range(n)])
print(numpy.mean(arr, axis=1), numpy.var(arr, axis=0), numpy.std(arr), sep='\n')
