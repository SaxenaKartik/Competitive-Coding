#include <bits/stdc++.h>
using namespace std;
long long p[10000010];
long long res[10000010];
void spf()
{

	for(int i=2;i<=10000000;i++)
	{
		if(!p[i])
		{	
			for(int j=2*i;j<=10000000;j+=i)
			{
				if(!p[j])
				{
					p[j]=i;
				}
			}
			res[i]=res[i-1]+i;
		}
		else
		{
			res[i]=res[i-1]+p[i];
		}
	}
}

int main()
{
	spf();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		printf("%lld\n", res[n]);
	}

}	