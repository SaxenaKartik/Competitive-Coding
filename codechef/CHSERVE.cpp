#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		ll k,p1,p2;
		scanf("%lld %lld %lld",&p1, &p2, &k);
		ll s=(p1+p2)/k;
		if(s%2==0)
		{
			printf("CHEF\n");
		}
		else
		{
			printf("COOK\n");
		}
	}
}