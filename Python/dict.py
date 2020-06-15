def test():
	words = list()
	dic = {
		'e': ["&"],
		'l': ["1", "|"]
	}
	OrigWord = "Hello"
	keys = dic.keys()
	for k in keys:
		vals = dic.get(k)
		for v in vals:
			words.append(OrigWord.replace(k, v))

	for w in words:
		print (w)

if __name__ == "__main__":
	test()

