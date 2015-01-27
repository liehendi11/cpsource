taste = []
calories = []
dp = []
n = 0
k = 0

def reset():
	global dp
	dp = [[-1 for y in range(20002)] for z in range(102)]


def compute(idx, diff):
	curTaste = (curCalories*k) + (diff-100)

	if (idx == n):
		if (diff == 0):
			return curTaste
		else:
			return 0

	if (dp[idx][curCalories][diff] == -1):
		res = 0

		newCalories = curCalories + calories[idx]
		newTaste = curTaste + taste[idx]
		newDiff = newTaste - (newCalories*)



inp = [int (x) for x in raw_input().split(' ')]
n = inp[0]
k = inp[1]

taste = [int (x) for x in raw_input().split(' ')]
calories = [int (x) for x in raw_input().split(' ')]

