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
	int n, s;
	cin>>n>>s;

	vi v;

	int sum =0LL;
	int mini = INT_MAX;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(mini>x)
			mini = x;
		v.push_back(x);
		sum+=x;
	}

	if(s>sum)
	{
		cout<<-1<<endl;
		return 0;
	}

	int left = (sum-s)/n; //amount left in each barrel 
	int ans = min(left, mini);

	cout<<ans<<endl;
}
