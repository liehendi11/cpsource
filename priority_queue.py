class PriorityQueue:
	def __init__(self):
		self.data = []

	def top(self):
		if (len(self.data) !=0):
			return self.data[0]
		else:
			return None

	def orderUp(self, index):
		if (index!=0):
			parent=0

			if (index%2 ==0) parent = (index/2)-1
			else:
				parent= ((index+1)/2)-1

			if (self.data[parent] > self.data[index]):
				temp = self.data[parent]
				self.data[parent] = self.data[index]
				self.data[index] = temp

	def push(self, number):
		self.data.append(number)
		self.orderDown(len(self.data)-1)

	def orderDown(self, index):
		if ((((index+1) * 2) -1) < len(self.data)):
			int left = ((index+1)*2) -1
			int right = left+1

			if (right < len(self.data)):
				if ((self.data[index] > self.data[left]) and (self.data[index] > self.data[right]) and (self.data[left] < self.data[right])): #left is smallest
					temp = self.data[index]
					self.data[index] = self.data[left]
					self.data[left] = temp
					orderDown(left)
				elif ((self.data[index] > self.data[right]) && (self.data[right] < self.data[left])):


	def pop(self):
		temp = self.data[len(self.data)-1]
		self.data.pop()

		self.data[0] = temp


