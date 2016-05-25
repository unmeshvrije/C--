
class test():

	def static_var(varname, value):
		def decorate(func):
			setattr(func, varname, value)
			return func
		return decorate

	@static_var("counter", 0)
	def fun():
		fun.counter += 1
		print 'It is really fun, Counter = ',fun.counter

if __name__ == "__main__":
	#t = test()
	test.fun()
