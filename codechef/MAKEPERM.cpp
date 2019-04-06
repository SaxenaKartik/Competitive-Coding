#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[100005];
ll cnt[100009];

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n,count=0;
		memset(arr,0,sizeof(arr));
		memset(cnt,0,sizeof(cnt));
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&arr[i]);
			if(arr[i]<=n)
				cnt[arr[i]]++;
		}

		for(int i=1;i<=n;i++)
		{
			if(!cnt[i]) count++;
		}

		printf("%d\n",count);
	}
}