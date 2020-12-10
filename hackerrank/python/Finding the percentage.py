# https://www.hackerrank.com/challenges/finding-the-percentage/problem

from  functools import reduce

if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    marks_count = len(student_marks[query_name])
    percentage = reduce(lambda a,b : a + b, student_marks[query_name]) / marks_count
    print('{0:.2f}'.format(percentage))
