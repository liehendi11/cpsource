class Node:
	def __init__(self, start, end):
		self.start = start
		self.end = end
		self.minValue = 1000000000
		self.maxValue = 0
		self.left = None
		self.right = None

	def constructTree(self, numbers):
		if (self.start != self.end):
			mid = (self.start+self.end)/2

			self.left = Node(self.start, mid)
			res = self.left.constructTree(numbers)
			self.minValue = res[0]
			self.maxValue = res[1]

			self.right = Node(mid+1, self.end)
			res = self.right.constructTree(numbers)
			self.minValue = min(res[0], self.minValue)
			self.maxValue = max(res[1], self.maxValue)
		else:
			self.minValue = numbers[self.start]
			self.maxValue = numbers[self.start]

		return self.minValue, self.maxValue


	def findMax(self, start, end):
		# print (self.start, self.end, start, end)

		if ((self.start == start) and (self.end == end)):
			return self.maxValue

		res = 0
		mid = (self.start+self.end)/2
		if ((self.start <= start) and (start <= mid)):
			res = max(res, self.left.findMax(start, min(mid, end)))

		if ((mid+1 <= end) and (end <= self.end)):
			res = max(res, self.right.findMax(max(start,mid+1), end))

		return res

	def findMin(self, start, end):
		# print (self.start, self.end, start, end)

		if ((self.start == start) and (self.end == end)):
			return self.minValue

		res = 1000000000
		mid = (self.start+self.end)/2
		if ((self.start <= start) and (start <= mid)):
			res = min(res, self.left.findMin(start, min(mid, end)))

		if ((mid+1 <= end) and (end <= self.end)):
			res = min(res, self.right.findMin(max(start,mid+1), end))

		return res

	def traverse(self):
		if (self.left != None):
			self.left.traverse()

		print (self.start, self.end, self.minValue, self.maxValue)

		if (self.right != None):
			self.right.traverse()

numbers = [0,1,2,3,4,5,6]
root = Node(0, 6)
root.constructTree(numbers)
root.traverse()