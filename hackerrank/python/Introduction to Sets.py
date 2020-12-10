# https://www.hackerrank.com/challenges/py-introduction-to-sets/problem

def average(array):
    distinct = list(set(array))
    return reduce(lambda a,b: a + b,distinct) / len(distinct)

