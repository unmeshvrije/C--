@profile
def anagram_cluster(list):
	anagrams = {}
	for e in list:
		sig = str(sorted(e))
		if sig not in anagrams:
			anagrams[sig] = []
		anagrams[sig].append(e)
	result = []
	for variants in anagrams.values():
		result.extend(variants)
	print result

if __name__ == "__main__":
	import sys
	anagram_cluster(list(sys.argv))
