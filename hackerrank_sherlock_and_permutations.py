# Enter your code here. Read input from STDIN. Print output to STDOUT
import math

modulo = 1000000007
tc = input()

for i in range(tc):
    inp = [int(x) for x in raw_input().split(' ')]
    
    print (math.factorial(inp[0]+inp[1]-1)/(math.factorial(inp[0]) * math.factorial(inp[1]-1)))%modulo
