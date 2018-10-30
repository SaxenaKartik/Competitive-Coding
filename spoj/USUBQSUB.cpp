//trying with range update on BIT
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int BIT[5][1005][1005];
ll n,m;

void update(int no,int x,int y,ll val)
{	
	for(;x<=n;x+=x&-x)
	{
		for(int y1=y;y1<=n;y1+=y1&-y1)
		{
			BIT[no][x][y1]+=val;
		}
	}
}

ll query(int no, int x,int y)
{
	ll sum=0;
	for (; x>0 ; x-=x&-x)
	{
		for(int y1=y;y1>0; y1-=y1&-y1)
		{
			sum+=BIT[no][x][y1];
		}
	}
	return sum;
}

void update_range2D(int x1,int y1,int x2,int y2,int  val)
{
	//updating the first tree 
	update(0, x1, y1, val);
    update(0, x1, y2+1, -val);
    update(0, x2+1, y1, -val);
    update(0, x2+1, y2+1, val);

    // updating second tree
    update(1, x1, y1, val*(1-y1));
    update(1, x1, y2+1, val*y2);
    update(1, x2+1, y1, val*(y1-1));
    update(1, x2+1, y2+1, -val*y2);

    // updating third tree
    update(2, x1, y1, val*(1-x1));
    update(2, x1, y2+1, (x1-1)*val);
    update(2, x2+1, y1, val*x2);
    update(2, x2+1, y2+1, -x2*val);

    // updating fourth tree
    update(3, x1, y1, (x1-1)*(y1-1)*val);
    update(3, x1, y2+1, -y2*(x1-1)*val);
    update(3, x2+1, y1, -x2*(y1-1)*val);
	update(3, x2+1, y2+1, x2*y2*val);
}

ll query_n(int x,int y)
{
	return query(0,x,y)*x*y+query(1,x,y)*x+query(2,x,y)*y+query(3,x,y);
}

ll query_range2D(int x1, int y1, int x2, int y2) {
    ll sum = 0;
    sum += query_n(x2, y2) - query_n(x1-1, y2) - query_n(x2, y1-1) + query_n(x1-1, y1-1);
    return sum;
}

int main()
{
	scanf("%lld %lld", &n, &m);

	int type,x1,x2,y1,y2,k;
	while(m--)
	{
		scanf("%d %d %d %d %d", &type,&x1, &y1, &x2, &y2);
		if(type==2)
		{
			scanf("%d",&k);
			update_range2D(x1,y1,x2,y2,k);

			/*for(int k=0;k<4;k++)
			{
				printf("Tree No. : %d\n", k);
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						printf("%lld ",query(k,i,j));
					}
					printf("\n");
				}
				printf("\n\n");
			}*/
		}
		else if(type==1)
		{
			// scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%lld\n", query_range2D(x1,y1,x2,y2));
		}
	}
	return 0;
}