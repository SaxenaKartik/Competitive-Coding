#include <bits/stdc++.h>
using namespace std;

bool vis[10010];
queue <pair <int, int> >q;
bool p[10001];

void clear( queue<pair<int,int> >&q )
{
   queue<pair<int,int> > empty;
   swap( q, empty );
}

void isprime()
{
	p[0]=false;
	p[1]=false;
	for(int i=2;i<=10000;i++)
	{
		p[i]=true;
	}
	for(int i=2;i<=10000;i++)
	{
		if(p[i])
		{
			for(int j=2*i;j<=10000;j+=i)
			{
				p[j]=false;
			}
		}
	}
}


long long convert(int number,int position,int value)
{
	int ones=number%10;
	number/=10;
	int tens=number%10;
	number/=10;
	int hunderds=number%10;
	number/=10;
	int thousands=number%10;

	if(position==1)
	{
		return (thousands*1000 + hunderds*100 + tens*10 + value);
	}	

	if(position==2)
	{
		return (thousands*1000 + hunderds*100 + value*10 + ones);
	}

	if(position==3)
	{
		return (thousands*1000 + value*100 + tens*10 + ones);
	}

	if(position==4)
	{
		return (value*1000 + hunderds*100 + tens*10 + ones);
	}
}


long long bfs(int start,int l,int dest)
{
	vis[start]=true;
	q.push(make_pair(start,l));
	int flag=0;

	while(!q.empty())
	{
		int number=q.front().first;
		int level=q.front().second;
		q.pop();
		if(number==dest)
		{
			flag=1;
			return level;

		}

		for(int i=0;i<10;i++)
		{
			long long n1,n2,n3,n4;
			//thousands place
			if(i>0)
			{
				n4=convert(number,4,i);
				if(p[n4] && !vis[n4])
				{
					vis[n4]=true;
					q.push(make_pair(n4,level+1));
				}
			}

			//hundereds place

			n3=convert(number,3,i);
			if(p[n3] && !vis[n3])
			{
				vis[n3]=true;
				q.push(make_pair(n3,level+1));
			}
 				
			//tens place

			n2=convert(number,2,i);
			if(p[n2] && !vis[n2])
			{
				vis[n2]=true;
				q.push(make_pair(n2,level+1));
			}

			//ones place
			n1=convert(number,1,i);
			if(p[n1] && !vis[n1])
			{
				vis[n1]=true;
				q.push(make_pair(n1,level+1));
			}	

		}

	}
	if(flag==0)
	{
		return -1;
	}
}

int main()
{
	isprime();
	
	int t;
	cin>>t;
	while(t--)
	{
		clear(q);
		int s,d;
		cin>>s>>d;
		memset(vis,false,sizeof(vis));

		/*for(int i=0;i<10000;i++)
		{
			cout<<p[i]<<endl;
		}*/
		long long len=0;
		len=bfs(s,0,d);
		if(len>=0)
		{
			cout<<len<<endl;
		}
		else
		{
			cout<<"Impossible\n";
		}
	}
}
