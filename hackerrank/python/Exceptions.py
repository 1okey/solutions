# https://www.hackerrank.com/challenges/exceptions/problem

for n in range(0, int(input())):
    try:
        a, b = [int(n) for n in input().split(' ')]
        print(a // b)
    except ValueError as e:
        print(f'Error Code: {e}')
    except ZeroDivisionError as e:
        print(f'Error Code: {e}')
