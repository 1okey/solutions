# https://www.hackerrank.com/challenges/python-mutations/problem

def mutate_string(string, position, character):
    return ''.join(string[:position] + character + string[position + 1:])

