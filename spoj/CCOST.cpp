#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXR 500005
#define MAXV 10000005

int BIT[MAXV];
int ans[4*MAXR];
int r,mr,n;

typedef struct tree
{
	int x,y;
	int val;
}tree;

typedef struct qu
{
	int x,y,pos;
}quer;

bool compt(const tree &a,const tree &b)
{
	return a.y<b.y;
}

bool compq(const quer &a,const quer &b)
{
	return a.y<b.y;
}

void update(int x,int val)
{
	for(;x<=MAXV;x+=x&-x)
	{
		BIT[x]+=val;
	}
}

int query(int x)
{
	int sum=0;
	for(;x>0;x-=x&-x)
		sum+=BIT[x];
	return sum;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tree t[n+5];
		memset(BIT,0,sizeof(BIT));

		for(int i=0;i<n;i++)
		{	
			int x,y;
			int  val;
			scanf("%d %d %d",&x,&y,&val);
			x++;
			y++;
			t[i].x=x;
			t[i].y=y;
			t[i].val=val;
		}

		sort(t,t+n,compt);

		
		scanf("%d", &r);
		quer q[4*r+5];
		int curr;

		for(int i=0;i<r;i++)
		{
			int x1,y1,x2,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1++;
			y1++;
			x2++;
			y2++;
			curr=4*i;
			
			q[curr].x=x1-1;
			q[curr].y=y1-1;
			q[curr].pos=curr;

			q[curr+1].x=x2;
			q[curr+1].y=y1-1;
			q[curr+1].pos=curr+1;

			q[curr+2].x=x1-1;
			q[curr+2].y=y2;
			q[curr+2].pos=curr+2;

			q[curr+3].x=x2;
			q[curr+3].y=y2;
			q[curr+3].pos=curr+3;
		}

		mr=4*r;
		sort(q,q+mr,compq);

		int pre=0,qre=0;

		while(pre<n && qre<mr)
		{
			while(pre<n && t[pre].y<=q[qre].y)
			{
				update(t[pre].x,t[pre].val);
				pre++;
			}
			while(qre<mr && q[qre].y==q[qre+1].y)
			{
				ans[q[qre].pos]=query(q[qre].x);
				qre++;
			}
			ans[q[qre].pos]=query(q[qre].x);
			qre++;
		}

		for(int i=0;i<r;i++)
		{
			int k=4*i;
			printf("%d\n", ans[k]+ans[k+3]-ans[k+1]-ans[k+2]);
		}
	}
}