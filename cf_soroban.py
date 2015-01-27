number = input()

if (number == 0):
	print "O-|-OOOO"

while (number > 0):
	digit = number % 10
	number = number/10

	res = ""
	if (digit >= 5):
		res += "-O|"
	else:
		res += "O-|"

	digit = digit % 5

	for i in range(digit):
		res += "O"
	res += "-"

	for i in range(4-digit):
		res += "O"

	print res