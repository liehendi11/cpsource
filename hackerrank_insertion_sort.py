class Node:

	def __init__(self, data, value, parent=None):
		self.data = data
		self.parent = parent
		self.left = None
		self.right = None
		self.balanceFactor = 0
		self.value = 0

	def __str__(self):
		return str(self.data)

	def isLeftChild(self):
		if (self.parent == None):
			return False
		else:
			return (self.parent.left == self)

	def isRightChild(self):
		if (self.parent == None):
			return False
		else:
			return (self.parent.right == self)

	def printNode(self, degree=0):
		print (" "*degree) + str(self.data) + " " + str(self.balanceFactor)

		if (self.left != None): self.left.printNode(degree+1)
		if (self.right != None): self.right.printNode(degree+1)

	def isRoot(self):
		return (self.parent == None)



class AVLTree:
	def __init__(self):
		self.node = None
		self.numberOfElements = 0

	def put(self, key, val, currentNode = None):
		if (currentNode == None):
			if (self.node == None):
				self.node = Node(key, val)
				self.numberOfElements+=1
				return
			else:
				currentNode = self.node

		if (val > currentNode.data):
			if (currentNode.right != None):
				self.put(val, currentNode.right)
			else:
				currentNode.right = Node(key, val, currentNode)
				self.numberOfElements+=1
				self.updateBalance(currentNode.right)
		else:
			if (currentNode.left != None):
				self.put(val, currentNode.left)
			else:
				currentNode.left = Node(key, val, currentNode)
				self.numberOfElements+=1
				self.updateBalance(currentNode.left)

	def updateBalance(self, node):

		if ((node.balanceFactor < -1) or (node.balanceFactor > 1)):
			self.rebalance(node)
			#self.printTree()
			return

		if (node.parent != None):
			#this is okay, let's update parent's balance factor

			if (node.isRightChild()):
				node.parent.balanceFactor -=1
			elif (node.isLeftChild()):
				node.parent.balanceFactor +=1

			#if it is unstable, we are successful in breaking things up
			if (node.parent.balanceFactor != 0):
				self.updateBalance(node.parent)

	def leftRotate(self, rootNode):
		newRoot = rootNode.right
		
		if (rootNode.isLeftChild()):
			rootNode.parent.left = newRoot
		elif (rootNode.isRightChild()):
			rootNode.parent.right = newRoot
		elif (rootNode.isRoot()):
			self.node = newRoot

		newRoot.parent = rootNode.parent

		rootNode.parent = newRoot
		rootNode.right = newRoot.left
		if (newRoot.left != None):
			newRoot.left.parent = rootNode

		newRoot.left = rootNode

		rootNode.balanceFactor = rootNode.balanceFactor + 1 - min(newRoot.balanceFactor, 0)
		newRoot.balanceFactor = newRoot.balanceFactor + 1 + max(rootNode.balanceFactor, 0)

	def rightRotate(self, rootNode):
		newRoot = rootNode.left
		
		if (rootNode.isLeftChild()):
			rootNode.parent.left = newRoot
		elif (rootNode.isRightChild()):
			rootNode.parent.right = newRoot
		elif (rootNode.isRoot()):
			self.node = newRoot

		newRoot.parent = rootNode.parent

		rootNode.parent = newRoot
		rootNode.left = newRoot.right
		if (newRoot.right != None):
			newRoot.right.parent = rootNode

		newRoot.right = rootNode

		rootNode.balanceFactor = rootNode.balanceFactor + 1 - min(newRoot.balanceFactor, 0)
		newRoot.balanceFactor = newRoot.balanceFactor + 1 + max(rootNode.balanceFactor, 0)

	def rebalance(self, node):
		if (node.balanceFactor < 0):
			if (node.right.balanceFactor > 0):
				self.rightRotate(node.right)
			self.leftRotate(node)
		else:
			if (node.left.balanceFactor < 0):
				self.leftRotate(node.left)
			self.rightRotate(node)

	def printTree(self):
		if (self.node == None): return
		self.node.printNode()

	def clear(self):
		self.node = None

	def find(self, data, currentNode=None):
		if (currentNode == None):
			currentNode = self.node

		if (currentNode == None): return None
		if (data == currentNode.data):
			return currentNode
		elif (data > currentNode.data):
			return self.find(data, currentNode.right)
		else:
			return self.find(data, currentNode.left)

	def getTreeSize(self):
		return self.numberOfElements

t = input()
for z in range(t):
	n = input()
	bil = [int(x) in raw_input().split(' ')]

	tree = AVLTree()

	for i in range(n):
		x = bil[i]
		findNode = tree.find(x)

		if (findNode == None): #the first
			tree.put(x, i)
		else:
			findNode.value +=1
