#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll n;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		ll bit=0,nibble=0,byte=0;
		scanf("%lld", &n);
		ll rem=n%26;
		ll cycle=n/26;
		if(rem>=1 && rem<=2)
		{
			bit=pow(2,cycle);
		}
		else if(rem>=3 && rem<=10)
		{
			nibble=pow(2,cycle);
		}
		else if(rem>=11 && rem<=25)
		{
			byte=pow(2,cycle);
		}
		else
		{
			byte=pow(2,cycle-1);
		}
		printf("%lld %lld %lld\n",bit,nibble,byte);
	}
}