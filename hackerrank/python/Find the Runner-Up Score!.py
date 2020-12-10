# https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem

import bisect

if __name__ == '__main__':
    n = int(input())
    max_n = -101
    prev_n = -101
    for n in [int(n) for n in input().split()]:
        if n > max_n:
            prev_n = max_n
            max_n = n
        elif n < max_n:
            prev_n = n if n > prev_n else prev_n

    print(prev_n)

