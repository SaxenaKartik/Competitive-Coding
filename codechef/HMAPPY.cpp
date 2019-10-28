#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100005

struct elements
{
	ll a,b,c;
};

ll n,m;
elements arr[SIZE];

/*bool cmp(elements x, elements y)
{
	return (x.c)>(y.c);
}*/

set <vector<ll> >s;

int main()
{
	scanf("%lld %lld",&n,&m);
	ll balloons=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld", &arr[i].a);
	}
	int count=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld", &arr[i].b);
		arr[i].c=arr[i].b*arr[i].a;
		balloons+=arr[i].a;
	}

	if(m>=balloons)
	{
		printf("0\n");
		return 0;
	}

	int i=n;
	ll k;
	while(i>0)
	{
		k=min(m,arr[i].a);
		s.insert({arr[i].c-k*arr[i].b,arr[i].b,k});
		m-=k;
		i--;
	}
	
	for(auto x : s)
	{
		printf("%lld %lld %lld\n",x[0],x[1],x[2]);
	}

	return 0;
}