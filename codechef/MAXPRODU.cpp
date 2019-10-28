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
typedef long long int lli;
#define int lli
typedef vector<int> vi;
typedef pair<int, int> pii;
#define mod 1000000007

int32_t main()
{
	// fast_io();
	int t;
	cin>>t;

	while(t--)
	{
		int n, k;
		cin>>n>>k;

		vector<int> v;
		int dist = n-(((k+1)*(k+2))/2-1);
		dist = (dist/k);
		for (int i = 0; i < k; ++i)
		{
			v.push_back(dist);
		}

		int temp = 2;
		//		debug(v);

		for (int i = 0; i < k; ++i)
		{
			v[i] += temp;
			temp++;
		}

		sort(all(v));
		int diff = n-accumulate(all(v), 0);
		if(diff)
		{
			for(int i = k-1; i >= 0 && diff; i--)
			{
				v[i]++;
				diff--;
			}
		}
		if(v[0] <= 1 || diff < 0)
		{
			cout<<-1<<"\n";
			continue;
		}
		int prod = 1;
		for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		{
			prod = ((prod%mod) * ((*i)%mod))%mod;
		}
		for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		{
			prod = ((prod%mod) * ((*i-1)%mod))%mod;
		}
		cout<<prod<<"\n";
	}
	return 0;
}