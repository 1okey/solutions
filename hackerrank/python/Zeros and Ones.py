# https://www.hackerrank.com/challenges/np-zeros-and-ones/problem

from numpy import ones, zeros, int

size = [int(n) for n in input().split(' ')]
print(zeros(size, dtype=int), ones(size, dtype=int), sep='\n')
