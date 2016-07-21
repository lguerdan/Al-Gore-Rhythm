#! /usr/bin/python

class Node:

  def __init__(self, value):
    self.value = value
    self.next = None


class LinkedList:

  def __init__(self):
    self.head = None

  def push(self, new_val):
    new_node = Node(new_val)
    new_node.next = self.head
    self.head = new_node

  def print_list(self):
    temp = self.head
    while(temp):
      print(temp.value)
      temp = temp.next

  def find_loop(self):
    slow_p = self.head
    fast_p = self.head
    while(slow_p and fast_p and fast_p.next):
      slow_p = slow_p.next
      fast_p = fast_p.next.next

      if slow_p == fast_p:
        print slow_p.value
        return slow_p

    return None

llist = LinkedList()

llist.push(5)
llist.push(10)
llist.push(18)
llist.push(5)
llist.push(25)
llist.push(15)

llist.print_list()

llist.head.next.next = llist.head
print llist.find_loop().value