#include <bits/stdc++.h>
using namespace std;

int sieve[100005];

void sievefunc()
{	
	for(int i=2;i<=100000;i++)
	{
		if(sieve[i]==0)
		{	
			sieve[i]=1;
			for(int j=2*i;j<=100000;j+=i)
			{
				sieve[j]++;
			}
		}
	}
}

int main()
{
	sievefunc();
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int a,b,x;
		scanf("%d %d %d",&a,&b,&x);
		int count=0;
		for(int i=a;i<=b;i++)
		{
			if(sieve[i]==x)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}