# https://www.hackerrank.com/challenges/ginorts/problem

chars = input()
even = []
odd = []
lowercase = []
uppercase = []
for c in chars:
    if c.isnumeric():
        even.append(c) if int(c) % 2 == 0 else odd.append(c)
    if c.isupper():
        uppercase.append(c)
    if c.islower():
        lowercase.append(c)

lowercase.sort()
uppercase.sort()
odd.sort()
even.sort()

print(''.join(lowercase + uppercase + odd + even))
