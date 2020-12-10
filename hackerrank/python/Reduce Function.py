# https://www.hackerrank.com/challenges/reduce-function/problem

def product(fracs):
    t = reduce(lambda lhs, rhs: lhs * rhs, fracs)
    return t.numerator, t.denominator
