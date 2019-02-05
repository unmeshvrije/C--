from resource import getrusage,RUSAGE_SELF

def array_test():
	test = {}
	test['1'] = ['A']
	#test['1'] = 'A'
	test['2'] = 'B'
	test['1'].append('C')
	print (test)
	print (getrusage(RUSAGE_SELF).ru_maxrss)

if __name__ == "__main__":
	import sys
	array_test()
