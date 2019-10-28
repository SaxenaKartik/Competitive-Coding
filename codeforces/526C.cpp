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

#define M 1000000007;

int32_t main()
{
	fast_io();
	string s;
	cin>>s;
	vi v;
	int cnt =0;
	for (int i = 0; i <(int) s.length(); i++)
	{
		if(s[i]=='a')
		{
			// if(s[i]=='a')
				cnt++;
		}
		else if(s[i]=='b' && cnt!=0)
		{
			v.push_back(cnt);
			cnt = 0;
		}
	}
	v.push_back(cnt);
	int prod=1;
	for(auto x : v)
	{
		prod=prod* (x+1);
		prod%=M;
	}
	cout<<prod-1<<endl;
}
