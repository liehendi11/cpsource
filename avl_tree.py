class Node:
	def __init__(self, data, parent=None):
		self.data = data
		self.parent = parent
		self.left = None
		self.right = None
		self.balanceFactor = 0

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

	def put(self, val, currentNode = None):
		if (currentNode == None):
			if (self.node == None):
				self.node = Node(val)
				return
			else:
				currentNode = self.node

		if (val > currentNode.data):
			if (currentNode.right != None):
				self.put(val, currentNode.right)
			else:
				currentNode.right = Node(val, currentNode)
				self.updateBalance(currentNode.right)
		else:
			if (currentNode.left != None):
				self.put(val, currentNode.left)
			else:
				currentNode.left = Node(val, currentNode)
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

tree = AVLTree()
tree.put(10)
tree.printTree()
print "-"*10

tree.put(20)
tree.printTree()
print "-"*10

tree.put(30)
tree.printTree()
print "-"*10

tree.put(40)
tree.printTree()
print "-"*10

tree.put(50)
tree.printTree()
print "-"*10

tree.put(60)
tree.printTree()
print "-"*10

tree.put(70)
tree.printTree()
print "-"*10

tree.put(80)
tree.printTree()
print "-"*10

tree.put(90)
tree.printTree()
print "-"*10

tree.put(100)
tree.printTree()
print "-"*10

tree.put(110)
tree.printTree()
print "-"*10
tree.put(120)
tree.printTree()



