for _ in range(int(input())):
	x,y,z=sorted(map(int,input().split()))
	s=str(min(x,4))+str(min(y,4))+str(min(z,4))
	g=['001','011','022','122','223','333','444','445']
	for i in range(8):
		if s<g[i]:
			print(i)
			break