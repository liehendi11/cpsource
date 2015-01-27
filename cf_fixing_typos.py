import sys

charArr = []
countArr = []

s = raw_input()

curChar = s[0]
curCount = 1

def process(start, end, twoIsFirst):
	if (twoIsFirst):
		deductor = 1
	else:
		deductor = 0

	for i in range(start, end+1):
		countArr[i] = deductor+1
		deductor = (deductor+1) %2


# preprocessing

for i in range(1,len(s)):
	if (s[i] != curChar):
		charArr.append(curChar)
		countArr.append(curCount)

		curChar = s[i]
		curCount=1
	else:
		curCount+=1

charArr.append(curChar)
countArr.append(curCount)

two = True
typo = True
count = 0
curSum = 0

for i in range(len(countArr)):
	if (countArr[i] == 1):
		if (two and typo):
			if (count %2 ==0):
				process(i-count, i-1, True)
			else:
				reducedTwo = curSum - (2* ((int) (count/2) +1)) - ((int) (count/2))
				reducedOne = curSum - (2* ((int) (count/2))) - ((int) (count/2)) -1

				if (reducedTwo < reducedOne):
					process(i-count, i-1, True)
				else:
					process(i-count, i-1, False)

		# reset everything
		two = False
		typo = False
		count = 0
		curSum = 0

	if (countArr[i] == 2):
		if (two):
			typo = True
		else:
			two = True
		count+=1
		curSum+=countArr[i]

	if (countArr[i] >2):
		typo = True
		two = True
		count +=1
		curSum+=countArr[i]

l = len(countArr)

if (two and typo):
	if (count %2 ==0):
		process(l-count, l-1, True)
	else:
		reducedTwo = curSum - (2* ((int) (count/2) +1)) - ((int) (count/2))
		reducedOne = curSum - (2* ((int) (count/2))) - ((int) (count/2)) -1

		if (reducedTwo < reducedOne):
			process(l-count, l-1, True)
		else:
			process(l-count, l-1, False)


for i in range(l):
	for j in range(countArr[i]):
		sys.stdout.write(charArr[i])

sys.stdout.write("\n")

