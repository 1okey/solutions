# https://www.hackerrank.com/challenges/any-or-all/problem

def is_palindrome(n):
    n_str = str(n)
    n_reversed = ''.join(reversed(list(str(n))))
    return n_str == n_reversed

def meet_conditions(nums):
    all_positive = all([n > 0 for n in nums])
    is_any_palindrome = any([is_palindrome(n) for n in nums])
    
    return all_positive and is_any_palindrome

n = int(input())
nums = [int(n) for n in input().split()]
print(meet_conditions(nums))
