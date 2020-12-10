# https://www.hackerrank.com/challenges/python-lists/problem

if __name__ == '__main__':
    N = int(input())
    arr = list()
    for n in range(0, N):
        query = input().split(' ')
        command = query.pop(0)
        if command == 'remove':
            item = int(query.pop())
            arr.remove(item)
        elif command == 'insert':
            item = int(query.pop())
            index = int(query.pop())
            arr.insert(index, item)
        elif command == 'print':
            print(arr)
        elif command == 'sort':
            arr.sort()
        elif command == 'append':
            arr.append(int(query.pop()))
        elif command == 'pop' and len(arr) > 0 :
            arr.pop()
        elif command == 'reverse':
            arr.reverse()
