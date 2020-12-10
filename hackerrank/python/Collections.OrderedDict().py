# https://www.hackerrank.com/challenges/py-collections-ordereddict/problem

from collections import OrderedDict
n = int(input())
vocab = OrderedDict()
for i in range(n):
    query = input().split(' ')
    key = ' '.join(query[0:-1])
    value = int(query[-1])
    if key in vocab:
        vocab[key] += value
    else:
        vocab[key] = value

for key in vocab:
    print(key, vocab[key], sep=' ')
