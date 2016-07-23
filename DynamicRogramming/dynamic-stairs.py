
memo = [-1] * 50

def num_ways(stairs):
  if stairs == 0:
    return 0
  elif stairs == 1:
    return 1
  elif stairs == 2:
    return 2

  if memo[stairs] == -1:
    memo[stairs] = num_ways(stairs - 3) + num_ways(stairs - 2) + num_ways(stairs - 1)

  return memo[stairs]

print num_ways(10)