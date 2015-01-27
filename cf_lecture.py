#import sys

inp = [int(x) for x in raw_input().split(' ')]

n = inp[0]
m = inp[1]
dict1 = {}
dict2 = {}

for i in range(m):
	inp = raw_input().split(' ')
	dict1[inp[0]] = inp[1]
	dict2[inp[1]] = inp[0]

words = raw_input().split(' ')

for i in range(len(words)):
	if (dict1.has_key(words[i])):
		if (len(words[i]) > len(dict1[words[i]])):
			words[i] = dict1[words[i]]
	else:
		if (len(words[i]) > len(dict2[words[i]])):
			words[i] = dict2[words[i]]

print " ".join(str(e) for e in words)