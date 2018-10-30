#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ofstream of;
	of.open("KAUSANDNIHA Input file #1");
	of<<"10\n";
	for(int i=0;i<10;i++)
	{
		ll n=rand()%100 + 2 ;
		ll m=rand()%100 + 1;
		of<<n<<" "<<m<<" "<<"\n";
		for(int j=0;j<m;j++)
		{
			int u,v;
			u=rand()%n+1;
			v=rand()%n+1;
			if(u!=v) //to make sure there are no roads when start and end locations are same 
				of<<u<<" "<<v<<" "<<rand()%1000+1<<"\n";
			else
				of<<u<<" "<<u+1<<" "<<rand()%1000+1<<"\n";
		}
		ll q=rand()%1000+1;
		of<<q<<"\n";
		for(int i=0;i<q;i++)
		{
			int x,y;
			x=rand()%n+1;
			y=rand()%n+1; 
			of<<x<<" "<<y<<"\n";
		}
	}
}