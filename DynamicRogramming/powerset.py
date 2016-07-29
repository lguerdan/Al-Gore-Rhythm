# Given a set of items, return all subsets of the set. (powerset)

set = ['a', 'b', 'c', 'd']
subsets = ['']

def subsets(nums):
  if nums is None: return None
  subsets = [[]]
  next = []
  for element in set:
    for s in subsets:
      next.append(s + [element])
    subsets += next
    next = []
  return subsets

print subsets(set)