#! usr/bin/python


def fib(num):
  if num == 0:
    return 0
  if num == 1:
   return 1
  return fib(num - 1) + fib(num - 2)


memo = [0] * 130

def fib_memoized(num):
  if num == 0 or num == 1:
    return num
  if memo[num] == 0:
    memo[num] = fib_memoized(num - 1) + fib_memoized(num - 2)
  return memo[num]

def fib_memoized_up(num):
  if num == 0:
    return 0

  a = 0
  b = 1
  for i in range(2,num):
    c = a + b
    a = b
    b = c

  return a + b

print fib(5)
print fib_memoized(5)
print fib_memoized_up(5)