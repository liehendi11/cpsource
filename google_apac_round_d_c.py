import sys

if (len(sys.argv) >1):
	inf = open(str(sys.argv[1])+".in", "r")
	outf = open(str(sys.argv[1])+".out", "w")
else:
	inf = sys.stdin
	outf = sys.stdout

tc = int(inf.readline().strip())

for z in range(0, tc):
	n = int(inf.readline().strip())

	departure = {}
	arrival = {}

	for i in range(0, n):
		source = inf.readline().strip()
		dest = inf.readline().strip()
		departure[source] = dest
		arrival[dest] = source

	sourceCity = ""

	for key in departure:
		if (not(key in arrival)):
			sourceCity = key
			break

	output = "Case #"+str(z+1)+":"

	while (True):
		output+= (" "+sourceCity+"-"+departure[sourceCity])
		sourceCity = departure[sourceCity]

		if (not sourceCity in departure):
			break

	outf.write(output+"\n")

inf.close()
outf.close()
