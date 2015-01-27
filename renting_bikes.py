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

dpMoney = []
dpMoney.append(0)
temp = 0
for i in range(len(price)):
	temp+=price[i]
	dpMoney.append(temp)


maxValue = 0
moneySpent = 0

treshold = max(0, len(money) - len(price))
minRange = treshold
maxRange = len(money)-1

while (minRange <= maxRange):
	#binary search no 1: finding number of kids to rent
	mid = (minRange+maxRange)/2

	#mid => starting point of children
	firstBoyAfford = -1
	minBoy = 0
	maxBoy = len(price) - mid - 1

	while (minBoy <= maxBoy):
		midBoy = (minBoy+maxBoy)/2

		if (money[midBoy + mid] >= price[mid]):
			firstBoyAfford = midBoy
			maxBoy = midBoy-1
		else:
			minBoy = midBoy+1

	privateMoneySpent = 0
	if (firstBoyAfford == -1):
		# no one can afford anything
		privateMoneySpent = (dpPrice[0] - dpPrice[len(price)-mid]) - (dpMoney[mid] - dpMoney[len(money)])
	else:
		privateMoneySpent = (dpPrice[0] - dpPrice[firstBoyAfford+1]) - (dpMoney[mid] - dpMoney[mid+firstBoyAfford])

	if (privateMoneySpent <= a):
		maxValue = mid
		moneySpent = privateMoneySpent
		maxRange = mid-1
	else:
		minRange = mid+1

print (maxValue, moneySpent) 
