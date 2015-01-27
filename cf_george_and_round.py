inp = [int(x) for x in raw_input().split(' ')]
n = inp[0]
m = inp[1]

a = [int(x) for x in raw_input().split(' ')]
b = [int(x) for x in raw_input().split(' ')]

mapping = [False for x in range(1000002)]

for i in b:
	mapping[i] = True

ctr = 0
for i in a:
	if (mapping[i] == False):
		ctr+=1

print ctr