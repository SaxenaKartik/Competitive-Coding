#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		ll x,y;
		scanf("%lld %lld", &x, &y);

		if((x&1) && (y&1)) //both odd
		{
			printf("2\n");
		}
		else if((x&1 && y&1==0) || (y&1 && x&1==0)) //one even one odd
		{
			printf("4\n");
		}
		else //both even
		{
			printf("4\n");
		}
	}
	return 0;
}