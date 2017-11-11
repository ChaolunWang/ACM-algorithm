#travel selsmen problem with state compression dynamic programming
'''
5	#city numbers
0 0     #city coordinate
1 1
2 0
5 1
4 9
'''

from functools import wraps
import sets
import sys
import numpy as np
inf=10000000

def dist(x, y):
	return np.sqrt((int(x[0])-int(y[0]))**2+(int(x[1])-int(y[1]))**2)



def memo(func):
	cache={}
	@wraps(func)
	def wrap(*args):
		if args not in cache:
			cache[args]=func(*args)
		return cache[args]
	return wrap

@memo
def tsp(sol, v, u):
	if(v.issubset(sol) and u==('0', '0')):
		return 0

	if(v.issubset(sol) and u!=('0', '0')):
		return inf

	result=min(tsp(sol.union(sets.Set([tp])), v, tp)+dist(tp,u) for tp in v.difference(sol))
	return result
		
		

def main():
	i=0
	n=0
	s=sets.Set([])
	sol=sets.Set([])
	print(sys.stdin)
	for line in sys.stdin:
		i=i+1
		if i==1:
			n=int(line)
		else:
    			s.add(tuple(line.split()))

	print( tsp(frozenset(sol), frozenset(s), ('0','0')))
			


if __name__=="__main__":
	main()
