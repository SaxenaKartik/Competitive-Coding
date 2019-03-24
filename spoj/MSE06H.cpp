#include <bits/stdc++.h>
using namespace std;

long long n,m,k;
long long BIT[1009];

struct node{
	long long first;
	long long second;
};

node arr[1000009];

bool compare(const node a, const node b)
{
	return ((a.first==b.first)? (a.second < b.second) : (a.first < b.first));
}

void update(long long x,long long val)
{
	for(;x<=m;x+= x&-x)
	{
		BIT[x]+=val;
	}
}

long long query(long long x)
{
	long long sum=0;
	for(;x>0;x-= x&-x)
	{
		sum+=BIT[x];
	}
	return sum;
}

int main()
{
	long long i,j,t,count=1,ans;
	scanf("%lld", &t);
	while(t--)
	{
		memset(BIT,0,sizeof(BIT));
		scanf("%lld %lld %lld", &n, &m, &k);

		for(i=0;i<k;i++)
		{
			scanf("%lld %lld",&arr[i].first,&arr[i].second);
		}	
		sort(arr,arr+k,compare);

		ans=0;
		for(long long i = k-1; i >= 0; i = j) 
		{
			for(j = i; j >= 0 && arr[j].first == arr[i].first; j--) ans += query(arr[j].second - 1);
			for(j = i; j >= 0 && arr[j].first == arr[i].first; j--) update(arr[j].second, 1);
		}
		// count++;
		printf("Test case %lld: %lld\n",count++, ans);
	}
	return 0;
}