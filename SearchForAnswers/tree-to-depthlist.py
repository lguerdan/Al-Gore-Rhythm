class Node:
  def __init__(self, key):
    self.data = key
    self.left = None
    self.right = None

def print_level_order(root):
  if root is None:
    return
  queue = []

  queue.append(root)

  while(len(queue) > 0):
    print queue[0].data,
    node = queue.pop(0)

    if node.left is not None:
      queue.append(node.left)
    if node.right is not Node:
      queue.append(node.right)


root = Node(1)
root.right = Node(4)
root.left = Node(5)
root.left.right = Node(2)
root.right.left = Node(7)

printLevelOrder(root)
print_level_order(root)


