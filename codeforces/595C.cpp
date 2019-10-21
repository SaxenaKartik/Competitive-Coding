#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#else
#define debug(...) 0
#endif
typedef long long int ll;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> pii;

int t;

int32_t main()
{
	fast_io();
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n+1];
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			arr[i] = x;
		}
		vi v(n+1);
		for(int i=1;i<=n;i++)
		{
			if(v[i])
			{
				continue;
			}
			int x = arr[i];
			int c = 1;
			while(x!=i)
			{
				x = arr[x];
				c++;
			}
			x = i;
			for(int j = 0;j<c;j++)
			{
				v[x] = c;
				x = arr[x];
			}
		}
		for(auto x:v)
		{
			if(x)
			{

				cout<<x<<" ";
			} 
					
		}
		cout<<endl;
	}
}
