#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll a[105];

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n;
		ll k,sum=0;
		scanf("%d %lld", &n, &k);

		for(int i=1;i<=n;i++)
		{
			scanf("%lld", &a[i]);
			sum+=a[i];
			if(sum>k)
			{
				printf("0");
				sum-=a[i];
			}
			else
			{
				printf("1");
			}
		}
		printf("\n");
	}
}