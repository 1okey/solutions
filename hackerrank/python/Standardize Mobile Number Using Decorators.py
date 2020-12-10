# https://www.hackerrank.com/challenges/standardize-mobile-number-using-decorators/problem

def wrapper(f):
    def fun(l):
        return f([f'+91 {num[-10:-5]} {num[-5:]}' for num in l])
    return fun
