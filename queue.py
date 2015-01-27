class Node:
	def __init__(self, data, next = None):
		self.data = data
		self.next = next

class TreeNode:
	def __init__(self, data):
		self.data = data
		self.children = []

class Queue:
	def __init__(self):
		self.head = None
		self.tail = None

	def push(self, number):
		if (self.tail == None):
			self.tail = Node(number)
			self.head = self.tail
		else:
			newNode = Node(number)
			if (self.tail == self.head):
				self.head.next = self.tail

			self.tail.next = newNode
			self.tail = newNode


	def pop(self):
		if (self.head != None):
			self.head = self.head.next
			if (self.head == None):
				self.tail = None

	def front(self):
		return self.head.data

	def iterate(self):
		traverse = self.head

		while (traverse!=None):
			print traverse.data
			traverse = traverse.next

class Stack:
	def __init__(self):
		self.head = None

	def push(self, number):
		newNode = Node(number, self.head)
		self.head = newNode

	def pop(self):
		if (self.head != None):
			self.head = self.head.next

	def top(self):
		if (self.head != None):
			return self.head.data

class Tree:
	def __init__(self):
		self.root = None




q = Queue()
s = Stack()

q.push(10)
q.push(20)
q.push(30)

s.push(10)
s.push(20)
s.push(30)

#q.iterate()
print q.front()
q.pop()
print q.front()
q.pop()
print q.front()
q.pop()

print s.top()
s.pop()
print s.top()
s.pop()
print s.top()
s.pop()
# print q.front()
# q.pop()
