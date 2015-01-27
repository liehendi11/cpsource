numbers = []
dp = []

def reset():
	global dp, numbers
	numbers = [0 for x in range (100003)]
	dp = [-1 for x in range (100003)]

def compute2():
	global dp, numbers
	x = 100000

	dp[100002] = 0
	dp[100001] = 0
	while (x >= 1):
		if (numbers[x] > 0):
			dp[x] = max(dp[x+1], dp[x+2] + (numbers[x] * x))
		else:
			dp[x] = dp[x+1]

		x-=1

	print dp[1]

reset()
n = input()

for x in raw_input().split(' '):
	numbers[int(x)] += 1

compute2()

