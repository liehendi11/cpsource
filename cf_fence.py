inp = [int (x) for x in raw_input().split(' ')]
n = inp[0]
k = inp[1]

numbers = [int(x) for x in raw_input().split(' ')]
dp = []

temp = 0
dp.append(0)
for i in range(n):
	temp += numbers[i]
	dp.append(temp)


minVal = 150000000
minIdx = 0
for i in range(n-k+1):
	curSum = dp[i+k] - dp[i]
	if (minVal > curSum):
		minVal = curSum
		minIdx = i

print minIdx+1
