#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll BIT1[505][505];
ll BIT2[505][505];

ll n,m; 

/*void init()
{
    ll i,j;
    for(i=0;i<505;i++)
    {
        for(j=0;j<505; j++)
        {
            BIT1[i][j]=BIT2[i][j]=0;
        }
    }
}*/

void update(ll BIT[][505], ll x, ll y, ll val)
{
	// for(;x<=n;x+=x&-x)
	// {
	for(; y<=m; y+=y&-y)
		BIT[x][y]+=val;
	// }
}

ll query(ll BIT[][505], ll x, ll y) 	
{
	ll sum=0;
	// for(; x>0;x-=x&-x)
	// {
	for(; y>0; y-=y&-y)
		sum+=BIT[x][y];
	// }
	return sum;
}

void update_range(ll x, ll y1, ll y2, ll v)
{
	update(BIT1, x, y1, v);
	update(BIT1, x, y2+1, -v);
	update(BIT2, x, y1, v*(y1-1));
	update(BIT2, x, y2+1, -v*y2);
}

void update_range2D(ll x1, ll y1, ll x2, ll y2, ll val)
{
	for(ll i=x1;i<=x2;i++)
	{
		update_range(i,y1,y2,val);
	}
}	

ll query_RC(ll x, ll y)
{
	return query(BIT1, x, y)*y-query(BIT2, x, y);
}

ll query_range(ll x, ll y1, ll y2)
{
	return query_RC(x,y2)-query_RC(x,y1-1);
}

ll query_range2D(ll x1, ll y1, ll x2, ll y2)
{
	ll sum=0;
	for(ll i=x1; i<=x2; i++)
	{
		sum+=query_range(i,y1,y2);
	}
	return sum;
}

int main()
{
	// init();
	ll val;
	scanf("%lld %lld", &n, &m);

	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			scanf("%lld", &val);
			update_range2D(i+1,j+1,i+1,j+1,val);
		}
	} 

	ll q,type,x1,x2,y1,y2;
	ll k;
	scanf("%lld", &q);

	/*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%lld ",query_range2D(i+1,j+1,i+1,j+1));
        }
        printf("\n");
    }*/

	while(q--)
	{
		scanf("%lld", &type);
		if(type==1)
		{
			scanf("%lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &k);
			update_range2D(x1,y1,x2,y2,k);
		}
		else
		{
			scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
			// for(int i=0;i<n;i++)
			// {
			// 	for(int j=0;j<m;j++)
			// 	{
			// 		printf("%lld ",query_range2D(i+1,j+1,i+1,j+1));
			// 	}
			// 	printf("\n");
			// }
			printf("%lld\n", query_range2D(x1,y1,x2,y2));

		}
	}
	return 0;
}