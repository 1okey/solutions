# https://www.hackerrank.com/challenges/write-a-function/problem

def is_leap(year):
    if year % 4 == 0:
        return year % 400 == 0 or year % 100 != 0

    return False
