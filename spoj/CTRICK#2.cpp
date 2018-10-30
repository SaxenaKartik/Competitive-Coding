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
			
		for (int i = 1; i <= n; i++)
		{
			/* code */
			update(i,1); //number of zeros upto that position
		}

		int rot=1,start=1,end=n;

		for (int i = n; i >0 ; i--)
		{
			/* code */
			rot=rot%i+1;
			start=1;end=n;
			while(start<=end) //search for the rot-th zero required
			{
				int mid=(start+end)>>1;
				if(query(mid)>=rot)
					end=mid-1;
				else start=mid+1;
			}
			a[start]=n-i+1;
			rot+=n-i+1;	
			update(start,-1);
		}

		
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		cout<<endl;
	}
}