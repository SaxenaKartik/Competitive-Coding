//using DSU
#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10005];
int size[10005];

int root(int x)
{
	while(arr[x]!=x)
	{
		arr[x]=arr[arr[x]]; //path compression
		x=arr[x];
	}
	return x;
}

void weighted_union(int a, int b)
{
	int root_a=root(a);
	int root_b=root(b);

	if(size[root_a]<size[root_b]) //union based on size
	{
		arr[root_a]=arr[root_b];
		size[root_b]+=size[root_a];
	}
	else if(size[root_a]>=size[root_b])
	{
		arr[root_b]=arr[root_a];
		size[root_a]+=size[root_b];
	}
	return;
}

bool find(int x, int y)
{
	if(root(x)==root(y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	
	// bool flag=false;

	for(int i=0;i<n;i++)
	{
		arr[i]=i;
		size[i]=1;
	}

	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x, &y);
		x-=1;
		y-=1;
		weighted_union(x,y);
	}

	int count=0;

	for(int i=1;i<n;i++)
	{	
		// printf("%d\n",root(i));
		if(find(i,i-1))
		{
			count++;
		}
	}

	// printf("%d\n",count);

	if(m==n-1 && count==n-1)
	{
		printf("YES\n");
	}
	else	
	{
		printf("NO\n");
	}

}