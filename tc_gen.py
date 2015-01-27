import random

f = open("end_up_with_more_teams.in","w")
try:
	for i in range(0, 100):
		f.write("14\n")
		for j in range(0,14):
			x = random.randint(1,10)
			f.write(str(x))
			if (j<13):
				f.write(" ")

		f.write("\n")

finally:
    f.close()

