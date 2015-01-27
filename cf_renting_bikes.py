inp = [int(x) for x in raw_input().split(' ')]
n = inp[0]
m = inp[1]
a = inp[2]

money = [int(x) for x in raw_input().split(' ')]
price = [int(x) for x in raw_input().split(' ')]

money.sort()
price.sort()

dpMoney = []
dpMoney.append(0)
temp = 0
for i in range(len(money)):
	temp+=money[i]
	dpMoney.append(temp)

dpPrice = []
dpPrice.append(0)
temp = 0
for i in range(len(price)):
	temp+=price[i]
	dpPrice.append(temp)

maxValue = 0
moneySpent = 0

print money
print price
print dpMoney
print dpPrice

treshold = max(0, len(money) - len(price))
minRange = treshold
maxRange = len(money)-1

while (minRange <= maxRange):
	#binary search no 1: finding number of kids to rent
	mid = (minRange+maxRange)/2


	# print treshold, mid

	#mid => starting point of children
	firstBoyAfford = -1
	minBoy = 0
	maxBoy = len(money)-mid-1

	while (minBoy <= maxBoy):
		midBoy = (minBoy+maxBoy)/2

		if (money[midBoy + mid] >= price[midBoy]):
			firstBoyAfford = midBoy
			maxBoy = midBoy-1
			# print midBoy, "Hooray"
		else:
			minBoy = midBoy+1

	leftOver = 0
	if (firstBoyAfford == -1):
		# no one can afford anything
		leftOver = dpPrice[len(money)-mid] - (dpMoney[len(money)] - dpMoney[mid])
		# print "Here 1", (dpPrice[len(money)-mid] - dpPrice[0]), (dpMoney[len(money)] - dpMoney[mid])
	else:
		leftOver = dpPrice[firstBoyAfford] - (dpMoney[mid+firstBoyAfford] - dpMoney[mid])
		print "Here 2/", dpPrice[len(money)-mid], dpPrice[firstBoyAfford] , (dpMoney[mid+firstBoyAfford] - dpMoney[mid]), price[firstBoyAfford], money[firstBoyAfford+mid]

	# print mid, firstBoyAfford, leftOver

	if (leftOver <= a):
		maxValue = mid
		moneySpent = max(dpPrice[len(money)-mid] - a, 0)
		maxRange = mid-1
		print mid, moneySpent, leftOver, firstBoyAfford
	else:
		minRange = mid+1

print len(money) - maxValue, moneySpent
