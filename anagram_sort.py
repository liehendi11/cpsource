def compare(item1, item2):
	return (1 if (''.join(sorted(item1)) < ''.join(sorted(item2))) else 0)

def sortAnagram(strings):
	return sorted(strings, cmp=compare)




strings = ["anna", "mwahaha", "hahaha", "voldemort", "nana"]

print ''.join(sorted("anna"))
print sortAnagram(strings)