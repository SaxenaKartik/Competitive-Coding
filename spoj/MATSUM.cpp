#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define SIZE 1050

ll BIT[SIZE][SIZE];
int R,C;

void update(int x,int y,int val)
{
	int x1,y1;
	for(x1=x; x1<=R; x1+=x1&-x1)
	{
		for(y1=y; y1<=C; y1+= y1&-y1)
		{
			BIT[x1][y1]+=val;
		}
	}
}

ll query(int x,int y)
{
	ll sum=0;
	int x1,y1;
	for(x1=x;x1>0;x1-=x1&-x1)
	{
		for(y1=y;y1>0;y1-=y1&-y1)
		{
			sum+=BIT[x1][y1];
		}
	}
	return sum;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		R=n;
		C=n;
		memset(BIT,0,sizeof(BIT));
		// memset(data,0,sizeof(data));
		
		while(true)
		{
			char s[50];
			scanf("%s",s);
			if(s[1]=='E')
			{
				int x,y;
				int num;
				scanf("%d %d %d", &x,&y,&num);
				x++;
				y++;
				ll previous=query(x,y)-query(x,y-1)-query(x-1,y)+query(x-1,y-1);
				update(x,y,num-previous);
			}
			else if(s[1]=='U')
			{
				int x1,x2,y1,y2;
				ll ans=0;
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				x1++;
				x2++;
				y1++;
				y2++;
				ans=query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1);
				printf("%lld\n", ans);
			}
			else
			{
				break;
			}
		}
		printf("\n");
	}
	return 0;
}