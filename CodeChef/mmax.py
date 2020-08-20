tc = int(input())
for i in range (0,tc,1):
	n = int(input())
	k = int(input())
	k = k%n
	if(n%2==0):
		if(k==0):
			ans=0
		elif(k>int(n/2)):
			ans=(n-1)-(2*(k-int(n/2)))
			ans=ans+1
		elif(k==int(n/2)):
			ans=int(n-1)
		else:
			ans=(n-1)-(2*(int(n/2)-k))
			ans=ans+1
		print(ans)
	else:
		if(k==0):
			ans=0
		elif(k>int(n/2)):
			n=n+1
			ans=(n-2)-(2*(k-int(n/2)))
		else:
			ans=(n-1)-(2*(int(n/2)-k))
		print(ans)
