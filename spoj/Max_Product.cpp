#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		int x,k;

		scanf("%d %d", &x, &k);

		int a=x/k;
		int rem=x%k;

		ll prod=1;

		while(k--)
		{
			if(rem)
			{
				prod=(prod*(a+1))%100000007;
				rem--;
			}
			else 
			{
				prod=(prod*(a))%100000007;
			}
		}

		printf("%lld\n",prod);

	}
}