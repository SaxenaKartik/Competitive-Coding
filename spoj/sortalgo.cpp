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

int32_t main()
{
	fast_io();
	int t;
	cin>>t;

	while(t--)
	{
		int n, i;
		cin>>n;
		int arr[n];
		bool mark[n+1] = {false};

		for(i = 0 ; i < n; i++)
		{
			cin>>arr[i];
		}

		vector<int>lis;
		int mx = 0;
		for(i = 0; i < n; i++)
		{
			if(arr[i] >= mx)
			{
				lis.push_back(arr[i]);
				mx = arr[i];
				mark[i] = true;
			}
		}
		debug(lis);

		//ans = lis.size();
		mx = 0;
		int ki = -1;
		int to_add = 0;
		for(i = 0; i < n; i++)
		{
			if(mark[i])
			{
				ki = -1;
				int cur_mx = mx;
				for(int j = i + 1; j < n; j++)
				{
					if(mark[j])
					{
						break;
					}
					if(arr[j] >= cur_mx)
					{
						ki++;
						cur_mx = arr[j];
					}
				}
				if(ki > to_add)
				{
					to_add = ki;
				}
				mx = arr[i];
			}
		}
		cout<<lis.size()+to_add<<"\n";
	}
	return 0;
}