# https://www.hackerrank.com/challenges/python-string-formatting/problem

def print_formatted(number):
    for n in range(1, number + 1):
        width = len("{0:b}".format(number))
        print(
            str(n).rjust(width, ' '),
            "{0:o}".format(n).rjust(width, ' '),
            "{0:X}".format(n).rjust(width, ' '),
            "{0:b}".format(n).rjust(width, ' ')
        )

