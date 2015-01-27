dp = []
n=0
s=0
l=0
root = None

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

		# print (self.start, self.end, self.minValue, self.maxValue)

		if (self.right != None):
			self.right.traverse()

def reset():
	global dp
	dp = [-1 for x in range(100002)]

def compute(curIdx):
	global n,s,l, dp, root
	if (curIdx == n):
		return 0

	if (dp[curIdx] == -1):
		res = n+2

		for i in range(l, n-curIdx+1):
			# print i
			if (abs(root.findMax(curIdx, curIdx+i-1) - root.findMin(curIdx, curIdx+i-1)) <= s):
				# print (abs(root.findMax(curIdx, curIdx+i-1) - root.findMin(curIdx, curIdx+i-1)), i, curIdx, curIdx+i-1)
				res = min(res, compute(curIdx+i) + 1)

		# print curIdx, res

		dp[curIdx] = res

	return dp[curIdx]	


inp = [int(x) for x in raw_input().split(' ')]

n = inp[0]
s = inp[1]
l = inp[2]

numbers = [int(x) for x in raw_input().split(' ')]

root = Node(0,n-1)
root.constructTree(numbers)

reset()

res = compute(0)
if (res <= n):
	print res
else:
	print -1
