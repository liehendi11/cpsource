firstTime = [int(x) for x in raw_input().split(':')]
secondTime = [int(x) for x in raw_input().split(':')]

# print firstTime
# print secondTime

firstTime[1] -= secondTime[1]
if (firstTime[1] < 0):
	firstTime[1] += 60
	secondTime[0] +=1

firstTime[0] -= secondTime[0]
if (firstTime[0] < 0):
	firstTime[0] += 24

first = str(firstTime[0])
if (len(first) < 2):
	first = "0"+first

second = str(firstTime[1])
if (len(second) < 2):
	second = "0"+second

print first+":"+second