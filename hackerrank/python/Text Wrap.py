# https://www.hackerrank.com/challenges/text-wrap/problem

def wrap(string, max_width):
    return '\n'.join([string[s: s + max_width] for s in range(0, len(string), max_width)])
