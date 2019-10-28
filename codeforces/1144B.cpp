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
	int n;
	int even=0,odd=0,sum=0;
	vi even_no;
	vi odd_no;
	cin>>n;
	int a[2001];
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
		if(a[i]%2==0) {
			even++;
			even_no.push_back(a[i]);
		}
		else {
			odd++;
			odd_no.push_back(a[i]);
		}
	}

	sort(even_no.begin(), even_no.end(), greater<int>());
	sort(odd_no.begin(), odd_no.end(), greater<int>());

	if(even<odd)
	{
		for(auto x: even_no)
			sum-=x;
		

		for(auto x:odd_no)
		{
			if(even==-1) break;
			sum-= x;
			even--;
		}
	}
	else
	{
		for(auto x: odd_no)
			sum-=x;

		for(auto x:even_no)
		{
			if(odd==-1) break;
			sum-= x;
			odd--;
		}
	}

	cout<<sum<<endl;

}
