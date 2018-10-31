// using Mo's algorithm (SQRT Decomposition)
// correction : using SQRT decomposition not Mo's algo 
// try not to use struct or vector when upper_bound or lower_bound is involved
#include <bits/stdc++.h>
using namespace std;

// #define ll long long
#define SIZE 30005

struct elements
{
	int value;
	int index;
};

elements arr[SIZE];

// pair<int,int> arr[SIZE];

struct cmp
{	
	bool operator()(elements a, elements b) const
	{
		return a.value<b.value;
	}
	bool operator()(elements a, int k) const
	{
		return a.value<k;
	}
 	bool operator()(int k, elements a) const
	{
		return k<a.value;
	}
};

int n,q,bucket,s=0;

int main()
{
	scanf("%d",&n);

	bucket=ceil(sqrt(n));

	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i].value);
		arr[i].index=i;
	}

	for(int i=0; i<n; i+=bucket)
	{
		sort(arr+i, arr + min(n, i+bucket),cmp());
	}

	scanf("%d",&q);

	while(q--)
	{
		// int a,b, c;
		int l,r,k;

		scanf("%d %d %d",&l,&r,&k);

		l^=s;
		r^=s;
		k^=s;

		l=max(1,l);
		r=min(n,r);

		l--;
		r--;
		s=0;

		int lblock=l/bucket;
		int rblock=r/bucket;

		int lstart=bucket*lblock;
		int rstart=bucket*rblock;

		for(int i=lstart; i<min(n,lstart+bucket); i++)
		{
			if(arr[i].index>=l && arr[i].index<=r &&arr[i].value>k) s++;
		}

		if(lblock!=rblock)
		{
			for(int i=rstart; i<min(n,rstart+bucket); i++)
			{
				if(arr[i].index>=l && arr[i].index<=r && arr[i].value>k) s++;
			}
			for(int i=lblock+1;i<rblock;i++)
			{
				int start=bucket*i;
				int total=upper_bound(arr + start, arr+ start + bucket,k,cmp())-arr-start;
				s+=max(0,bucket-total);
			}
		}
		printf("%d\n", s);
	}
	return 0;
}