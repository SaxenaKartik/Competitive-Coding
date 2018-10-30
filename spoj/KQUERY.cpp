//using BIT and offline query : individual property of elements in the query

#include <bits/stdc++.h>
using namespace std;
#define SIZE 30005

int BIT[SIZE];
int n,qu;

struct kquery
{
	int l;
	int r;
	int k;
	int num;
}q[200005];

struct num
{
	int index;
	int val; 
}a[SIZE];

bool cmp(num a, num b)
{
	return a.val>b.val;
}

bool cmp1(kquery a,kquery b)
{
	if(a.k==b.k)
	{
		return a.r>b.r;
	}
	return a.k>b.k;
}

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
	}
	return sum;
}

int main()
{
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
		a[i].index=i;
		BIT[i]=0;
	}
	sort(a+1,a+1+n,cmp);

	scanf("%d",&qu);

	int result[qu+5];

	for(int i=1;i<=qu;i++)
	{
		scanf("%d %d %d",&q[i].l,&q[i].r,&q[i].k);
		q[i].num=i;
	}

	sort(q+1,q+1+qu,cmp1);

	/*for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",a[i].val, a[i].index);
	}*/
/*
	for(int i=1;i<=qu;i++)
	{
		printf("%d %d %d %d\n",q[i].l,q[i].r,q[i].k,q[i].num);
	}*/

	int j=1;
	for(int i=1;i<=qu;i++)
	{
		while(j<=n && a[j].val>q[i].k)
		{
			update(a[j].index,1); /*marking the contribution of a number at a time 
									for all the queries that is being and are not yet 
									dealt with as the queries are in descending order*/
			j++;	
		}
		result[q[i].num]=query(q[i].r)-query(q[i].l-1);
	}

	/*for(int i=1;i<=n;i++)
	{
		printf("%d\n", query(i));
	}*/
	for(int i=1;i<=qu;i++)
	{
		printf("%d\n", result[i]);
	}
	return 0;
}