# https://www.hackerrank.com/challenges/capitalize/problem

def solve(s):
    return " ".join([c.capitalize() for c in s.split(' ')])

