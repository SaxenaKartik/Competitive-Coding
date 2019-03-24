#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ofstream of;
	of.open("AMANPNT Input file #2");
	of<<"100\n";
	for(int i=0;i<100;i++)
	{
		ll n=rand()%10000 + 2 ;
		ll m=rand()%10000 + 1;
		of<<n<<" "<<m<<" "<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%1000 + 2<<"\n";
		for(int j=0;j<m;j++)
		{
			int u,v;
			u=rand()%n+1;
			v=rand()%n+1;
			if(u!=v) //to make sure there are no roads when start and end locations are same 
				of<<u<<" "<<v<<"\n";
			else
				of<<u<<" "<<u+1<<"\n";
		}
	}
}