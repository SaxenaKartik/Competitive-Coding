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

int32_t main()
{
	fast_io();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	// sort(a+1, a+1+n);
	map<int, int> h;
	for(int i=1;i<=n;i++) {
		h[a[i]]++;
		// debug(x);
	}
	int max = 0;
	int ans;
	int ans_index;
	for(auto x:h) 
	{
		if(max<=x.second)
		{
			ans = x.first;
			max = x.second;
		}
	}


	// debug(ans);
	// int i=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==ans)
		{
			ans_index = i;
			break;
		}
		// i++;
	}
	// debug(ans_index);
	vector<pair<int,pii>> v;

	// i = 1;
	// int count = 0;
	for(int i=ans_index-1;i>=1;i--)
	{
		// count++;
		if(a[i]<a[i+1])
		{
			v.push_back({1,{i,i+1}});
		}
		else if(a[i]>a[i+1])
		{
			v.push_back({2,{i, i+1}});
		}
		a[i] = ans;
		// ans_index=i;
	}

	// for(int i = 1 ;i<=n;i++)
	// {
	// 	debug(a[i]);
	// }

	for(int i=ans_index+1;i<=n;i++)
	{
		// count++;
		if(a[i]<a[i-1])
		{
			v.push_back({1,{i,i-1}});
		}
		else if(a[i]>a[i-1])
		{
			v.push_back({2,{i, i-1}});
		}
		a[i] = ans;
		// ans_index=i;
	}

	cout<<n-max<<endl;
	for(auto x: v)
	{
		cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
	}
}
