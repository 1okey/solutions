# https://www.hackerrank.com/challenges/nested-list/problem

if __name__ == '__main__':
    students = [[input(), float(input())] for n in range(int(input()))]
    sorted_list = sorted(list(set([score for name, score in students])))
    second_score = sorted_list[1]
    second_lowest_studs = sorted([name for name, score in students if score == second_score])
    print(*second_lowest_studs, sep='\n')
