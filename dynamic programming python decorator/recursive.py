from functools import wraps

def memo(func):
	cache={}
	@wraps(func)
	def wrap(*args):
		if args not in cache:
			cache[args]=func(*args)
		return cache[args]
	return wrap

@memo
def cnk(n,k):
	if k==0: return 1
	if n==0: return 0
	return cnk(n-1,k)+cnk(n-1, k-1)

def main():
	print(cnk(200,2))

if __name__=="__main__":
	main()
