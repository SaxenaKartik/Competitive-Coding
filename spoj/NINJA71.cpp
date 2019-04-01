#include <bits/stdc++.h>
using namespace std;

#define size 100025

vector< long long int> active;
int a[size],b[size];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}

		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}
		active.clear();

		long long int sum=0,length=0,d;

		for(int i=0;i<n;i++)
		{
			d=a[i]-b[i];
			if(d>0)
			{
				length++;
				sum+=d;
			}
			else active.push_back(-d);
		}

		sort(active.begin(),active.end());

		for(int i:active)
		{
			if(i>sum)
				break;
			length++;
			sum-=i;
		}
		cout<<length<<endl;
	}
}