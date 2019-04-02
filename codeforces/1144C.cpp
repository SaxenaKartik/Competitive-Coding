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

int a[200005];
map<int, int> h;

int32_t main()
{
	fast_io();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		h[a[i]]++;
	}

	int flag = 0;
	vi fir;
	vi sec;

	for(auto x: h)
	{
		// cout<<x.first<<" "<<x.second<<endl;
		if(x.second>2)
			flag=1;
		else
		{
			fir.push_back(x.first);
			if(x.second==2)
			{
				sec.push_back(x.first);
			}

		}
	}


	if(flag==1)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		sort(fir.begin(), fir.end());
		sort(sec.begin(), sec.end(), greater<int>());
		cout<<"YES"<<endl;
		cout<<fir.size()<<endl;
		for(auto x : fir)
		{
			cout<<x<<" ";
		}
		cout<<endl;
		cout<<sec.size()<<endl;
		for(auto x : sec)
		{
			cout<<x<<" ";
		}
		cout<<endl;
	}
}
