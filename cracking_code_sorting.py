#question 1

def mergeArrays(arrA, arrB):
	xa = len(arrA)-1
	xb = len(arrB)-1
	pos = len(arrA) + len(arrB) - 1

	while (pos>=0):
		if (arrA[xa] > arrB[xb]):
			arrA[pos] = arrA[xa]
			xa-=1
			pos-=1
			if (xa <0):
				break
		else:
			arrA[pos] = arrB[xb]
			xb-=1
			pos-=1
			if (xb < 0):
				break

	if (xa < 0):
		while (xb >=0):
			arrA[pos] = arrB[xb]
			pos-=1
			xb-=1

	return arrA

def findStringWithEmptyStringList(strings, q):
	minRange = 0
	maxRange = len(strings)-1

	while (minRange <= maxRange):
		mid = (minRange+maxRange)/2

		# print minRange, mid, maxRange

		if (len(strings[mid]) != 0):
			if (strings[mid] == q):
				return mid
			elif (strings[mid] < q):
				minRange = mid+1
			else:
				maxRange = mid-1
		else:
			#empty string
			left = mid-1
			right = mid+1

			if (left <minRange):
				left=-1
			else:
				while (len(strings[left]) ==0):
					left -= 1
					if (left < minRange):
						left = -1
						break

			if (right > maxRange):
				right = -1
			else:
				while (len(strings[right]) ==0):
					right += 1
					if (right > maxRange):
						right = -1
						break

			# print mid, left, right

			if ((left != -1) and (right != -1)):
				if (strings[left] == q):
					return left
				elif (strings[right] == q):
					return right
				elif (strings[left] > q):
					maxRange = left-1
				elif (strings[right] < q):
					minRange = right+1
				else:
					return -1
			elif (left != -1):
				if (strings[left] == q):
					return left
				elif (strings[left] > q):
					maxRange = left-1
				else:
					return -1
			elif (right != -1):
				if (strings[right] == q):
					return right
				elif (strings[right] < q):
					minRange = right+1
				else:
					return -1
			else:
				return -1

	return -1

def bitsConvert(a, b):
	x = 1
	ctr=0

	while ((x <=a) or (x<=b)):
		maskedA = a&x
		maskedB = b&x

		if (maskedA!=maskedB):
			ctr+=1

		x <<=1

	return ctr

# strings = ["at", "", "", "", "ball", "car", "", "", "dad", "", ""]

print bitsConvert(31,0)

