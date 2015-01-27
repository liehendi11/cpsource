s = raw_input()

# get first number
idx = len(s)-1
prev = ""
ctr=0

while (s[idx] =='0'):
	prev += '0'
	idx-=1

prev += s[idx]
idx-=1
ctr=1

cur = ""

# print prev

while (idx >= 0):
	if (s[idx] == '0'):
		cur += s[idx]
		idx-=1
	else:
		cur += s[idx]
		idx-=1

		if (len(cur) > len(prev)):
			# print prev, cur
			prev = cur
			ctr+=1
			cur = ""
		elif(len(cur) == len(prev)):
			x = len(cur)-1
			isBigger = False
			isEqual = True
			while (x >= 0):
				if (cur[x] != prev[x]):
					isEqual = False

				if (cur[x] > prev[x]):
					isBigger = True
					break

				if (cur[x] < prev[x]):
					isBigger = False
					break				

				x-=1

			if ((isBigger) or (isEqual)):
				# print prev, cur
				prev = cur
				ctr+=1
				cur = ""


if (len(cur) > 0):
	if (len(cur) > len(prev)):
		ctr+=1
		
	elif(len(cur) == len(prev)):
		x = len(cur)-1
		isBigger = False
		isEqual = True
		while (x >= 0):
			if (cur[x] != prev[x]):
				isEqual = False

			if (cur[x] > prev[x]):
				isBigger = True
				break

			if (cur[x] < prev[x]):
				isBigger = False
				break				
				
			x-=1

		if ((isBigger) or (isEqual)):
			ctr+=1

print ctr