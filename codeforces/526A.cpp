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

	int a[105];

	int32_t main()
	{
		fast_io();
		int n;
		cin>>n;

		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}

		int res = INT_MAX;

		for(int i=1;i<=n;i++)
		{
			int x=i;
			int cost=0;
			for(int j=1;j<=n;j++)
			{
				cost+=a[j]*(abs(j-1) + abs(x-1) + abs(j-x))*2;
				// debug(x, cost);
			}
			res = min(res, cost);
		}

		cout<<res<<endl;
	}
