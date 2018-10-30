#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define SIZE 100005

ll sieve[1000005];
int n,q;
ll a[SIZE];

void sievefunc()
{
	sieve[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!sieve[i])
		{
			for(int j=i;j<=1000000;j+=i)
			{
				if(!sieve[j])
				{
					sieve[j]=i;
				}
			}
		}
	}
}

struct trees
{
	vector<int> v;
};

trees tree[SIZE<<4];


void build(int node,int start,int end)
{
	// printf("here\n");
	if(start>end) return;
	if(start==end)
	{
		ll x=a[start];
		// printf("%lld\n", x);
		
		int k=sieve[x];
		// printf("%d\n", k);

		tree[node].v.push_back(k);

		while(x!=k)
		{
			// printf("%d\n", tree[node].v.front());
			x/=k;
			k=sieve[x];
			tree[node].v.push_back(k);
		}

		/*for(int i=0;i<tree[node].v.size();i++)
		{
			printf("%d ", tree[node].v[i]);
		}
		printf("\n");*/
		return;
	}

	int mid=start+end>>1;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node].v.resize(tree[2*node].v.size()+tree[2*node+1].v.size());
	merge(tree[2*node].v.begin(),tree[2*node].v.end(),tree[2*node+1].v.begin(),tree[2*node+1].v.end(),tree[node].v.begin());
}

int query(int node, int start, int end, int l, int r, int x, int y)
{
	if(start>end || start>r || end<l)
	{
		return 0;
	}
	if(l<=start && end<=r)
	{
		int left,right;
        // if(x<y) 
        // {
    	left=lower_bound(tree[node].v.begin(),tree[node].v.end(),x)-tree[node].v.begin();
    	right=upper_bound(tree[node].v.begin(),tree[node].v.end(),y)-tree[node].v.begin();
    	return right-left;
        // }
        /*else 
        {
            left=upper_bound(tree[node].v.begin(),tree[node].v.end(),x)-tree[node].v.begin();
            right=lower_bound(tree[node].v.begin(),tree[node].v.end(),y)-tree[node].v.begin();
            return left-right;
        }*/
	}
	int mid=start+end>>1;
	return query(2*node,start,mid,l,r,x,y)+query(2*node+1,mid+1,end,l,r,x,y);
}

int main()
{
	sievefunc();
	/*for(int i=1;i<=1000000;i++)
	{
		printf("%d\n",sieve[i] );
	}*/
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	build(1,1,n);

	/*for(int i=1;i<=2*n-1;i++)
	{
		for(int j=0;j<tree[i].v.size();j++)
		{
			printf("%d ",tree[i].v[j]);
		}
		printf("\n");
	}*/

	scanf("%d",&q);
    int x,y,l,r;
    for(int i=1; i<=q; i++)
    {
        scanf("%d %d %d %d",&l,&r,&x,&y);
        printf("%d\n",query(1,1,n,l,r,x,y));
    }
    return 0;
}