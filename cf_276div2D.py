n = input()
bil = [int(x) for x in raw_input().split(' ')]

bil.sort()

retrievalArr = [-1 for x in range(bil[len(bil)-1] *2 +2)]
maxTres = len(retrievalArr)-1
i = len(bil)-1

while (i>=0):
	if (maxTres >= bil[i]):
		retrievalArr[maxTres] = i
		maxTres-=1
	else:
		i-=1

res = 0
for j in range(len(bil)):
	x = bil[j]*2

	while (x<= (bil[len(bil)-1] *2)):
		temp = retrievalArr[x]

		if (temp != -1):
			res = max(bil[temp] %bil[j], res)

		# print j, x, temp, temp%bil[j]
		x+=bil[j]

print res
