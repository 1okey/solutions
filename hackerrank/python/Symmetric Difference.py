# https://www.hackerrank.com/challenges/symmetric-difference/problem

m = int(input())
set_a = set(map(int, input().split(' ')))
n = int(input())
set_b = set(map(int, input().split(' ')))
diff = list(set_a.difference(set_b) | set_b.difference(set_a))
diff.sort()
print(*diff, sep='\n')
