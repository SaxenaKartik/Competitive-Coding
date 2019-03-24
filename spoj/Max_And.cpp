#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		ll a, b;
		scanf("%lld %lld", &a, &b);

		if(b&1)
		{
			printf("%lld\n",b-1);
		}
		else
		{
			printf("%lld\n",b-2);
		}
	}
}