#!/usr/bin/python

'''
This python script is used to iterate over
the all the cases in the input file and
run the cache-simulator program and print
it's output
'''

import os

f = open('INPUT')
print "#!/usr/bin/env sh\n"
t = int(f.readline().strip())
for i in range(t):
	c = int(f.readline().strip())
	b = f.readline().strip().split('/')
	a = f.readline().strip().split('/')
	m = int(f.readline().strip())
	nmp = []
	for j in range(m):
		nmp.append(f.readline().strip().split('x'))

	for bi in b:
		for ai in a:
			for nmpi in nmp:
				print "./sim %d %d %d %d %d %d"%(c, int(bi), int(ai), int(nmpi[0]), int(nmpi[1]), int(nmpi[2]))
