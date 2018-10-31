#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;
int sieve[100005];
int  n,q;
int a[100005];

void sievefunc()
{
	sieve[0]=0;
	sieve[1]=1;
	for(int i=2;i<=100000;i++)
	{
		if(!sieve[i])
		{
			for(int j=i;j<=100000;j+=i)
			{
				if(!sieve[j])
				{
					sieve[j]=i;
				}
			}
		}
	}
}

vector<pair<int,int> > primefactors(int a)
{
	vector<pair<int, int> > v;
	unordered_map<int, int> h;
	int k=sieve[a];
	// printf("%d\n", k);
	while(k!=1)
	{
		h[k]++;
		// printf("%d\n", h[k]);
		a=a/k;
		k=sieve[a];
	}

	unordered_map<int, int>::iterator it;
	// v.push_back(0);
	for(it=h.begin();it!=h.end();it++)
	{
		v.push_back(make_pair(it->first,it->second));
	}

	return v;	
}

struct trees
{
	vector<pair<int, int> > v;
	vector<int> prefix;
};

trees tree[100005<<3];

trees merge(trees a, trees b)
{
	trees res;
	/*vector<pair<int, int> >::iterator it1;
	vector<pair<int, int> >::iterator it2;*/

	unordered_map<int, int> m;

	for(int i=0;i<a.v.size();i++)
	{
		m[a.v[i].first]+=a.v[i].second;
	}

	for(int i=0;i<b.v.size();i++)
	{
		m[b.v[i].first]+=b.v[i].second;
	}

	unordered_map<int, int>::iterator it;
	// v.push_back(0);
	for(it=m.begin();it!=m.end();it++)
	{
		res.v.push_back(make_pair(it->first,it->second));
	}

	/*for(int i=0;i<res.v.size();i++)
	{
		printf("%d %d\n", res.v[i].first, res.v[i].second);
	}*/

	for(int i=0;i<res.v.size();i++)
	{
		if(i==0)
			res.prefix.push_back(res.v[i].second);
		else 
			res.prefix.push_back(res.prefix[i-1]+res.v[i].second);
	}
	return res;
}

/*bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.first<b.first;
}*/

void build(int node,int start,int end)
{
	if(start>end) return;
	if(start==end)
	{
		tree[node].v=primefactors(a[start]);

		// printf("%d\n",node );

		/*for(int i=0;i<tree[node].v.size();i++)
		{
			printf("%d %d\n",tree[node].v[i].first, tree[node].v[i].second);
		}*/
		// tree[node].prefix.push_back(0);

		for(int i=0;i<tree[node].v.size();i++)
		{
			if(i==0)
				tree[node].prefix.push_back(tree[node].v[i].second);
			else
				tree[node].prefix.push_back(tree[node].prefix[i-1]+tree[node].v[i].second);
		}

		/*for(int i=0;i<tree[node].prefix.size();i++)
		{
			printf("%d\n",tree[node].prefix[i]);
		}*/

		return;
	}
	int mid=start+end>>1;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=merge(tree[2*node],tree[2*node+1]);
}

int query(int node,int start,int end, int l,int r, int x, int y)
{
	if(start>r||end<l||start>end)
		return 0;
	if(l<=start && end<=r)
	{
		
		/*// printf("%d %d\n",left,right);
		vector<pair<int, int> >::iterator left;
		vector<pair<int, int> >::iterator right;*/

		int left,right;
		int s=start,e=end;

		while(s<e)
		{
			int mid=s+e>>1;
			if(x<=tree[node].v[mid].first)
				e=mid;
			else
				s=mid+1;
		}

		left=s;

		s=start;
		e=end;

		while(s<e)
		{
			int mid=s+e>>1;
			if(x>=tree[node].v[mid].first)
				s=mid+1;
			else
				e=mid;
		}

		right=l;

		printf("%d %d\n",left, right );
		/*left=lower_bound(tree[node].v.begin(), tree[node].v.end(), x, cmp)-tree[node].v.begin();
		right=upper_bound(tree[node].v.begin(), tree[node].v.end(), y, cmp)-tree[node].v.begin();*/
		return tree[node].prefix[right]-tree[node].prefix[left-1];
	}
	int mid=start+end>>1;
	return query(2*node,start,mid,l,r,x,y)+query(2*node+1,mid+1,end,l,r,x,y);
}

int main()
{
	sievefunc();

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}

	build(1,1,n);
	/*for(int i=2;i<=10;i++)
	{
		printf("%d\n",sieve[i]);
	}*/	

	/*vector<pair<int, int> >v;
	v=primefactors(10);
	for(int i=0;i<v.size();i++)
	{
		printf("%d %d\n",v[i].first, v[i].second);
	}*/


	/*for(int i=1;i<=2*n-1;i++)
	{
		for(int j=0;j<tree[i].v.size();j++)
			printf("%d %d ,",tree[i].v[j].first, tree[i].v[j].second);
		printf("\n");
		for(int k=0;k<tree[i].prefix.size();k++)
			printf("%d ",tree[i].prefix[k]);
		printf("\n\n");
	}*/

	scanf("%d",&q);
	int l,r,x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d %d %d", &l,&r,&x,&y);
		printf("%d\n", query(1,1,n,l,r,x,y));
	}
	return 0;
}