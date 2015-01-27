inp = [int(x) for x in raw_input().split(' ')]
n = inp[0]
x = inp[1]

curSum = 0
cur = 1

for i in range(n):
	inp = [int(a) for a in raw_input().split(' ')]

	jumps = int((inp[0]-cur)/x)

	# print cur, jumps, cur+(jumps*x), inp[1]-(cur+(jumps*x))+1
	cur += (jumps*x)
	curSum += inp[1]-cur+1
	cur = inp[1]+1

print curSum