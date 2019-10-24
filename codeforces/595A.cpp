#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
// #include "prettyprint.hpp"
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
		vi v;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
		int ans = 1;
		sort(v.begin(), v.end());
		for(int i = 1;i<n;i++)
		{
			if(v[i]-v[i-1]==1)
			{
				ans = 2;
				break;
			}
		}
		cout<<ans<<endl;
	}
}
