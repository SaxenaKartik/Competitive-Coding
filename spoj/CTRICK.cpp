#include <bits/stdc++.h>
using namespace std;
#define ll long long

int BIT[20005];
int n;

void update(int x,int val)
{
	for(;x<=n;x+=x&-x)
	{
		BIT[x]+=val;
	}
}

int query(int x)
{
	int sum=0;
	for(;x>0;x-=x&-x)
	{
		sum+=BIT[x];
		// cout<<sum<<endl;
	}
	return sum;
}

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		memset(BIT,0,sizeof(BIT));

		scanf("%d",&n);
		int a[n]={0};
		
		for(int i=1;i<=n;i++)
		{
			update(i,1);
		}
		
		int rot=1,cards=n,start,end;

		for(int i=1;i<=n;i++)
		{
			rot=(i+rot)%cards;
			if(!rot) rot=cards;
			cards--;
			start=1;end=n;
			while(start<=end)
			{
				int mid=(start+end)/2;
				if(query(mid)>=rot)	end=mid-1;
				else start=mid+1;
			}

			a[start]=i; 
			update(start,-1);
		}

		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		cout<<endl;
	}
}