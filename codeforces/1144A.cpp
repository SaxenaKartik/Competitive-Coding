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
int a[26];

int32_t main()
{
	fast_io();
	cin>>t;
	while(t--)
	{
		for(int i=0;i<26;i++)
		{
			a[i]=0;
		}
		string s;
		cin>>s;
		for(auto ch : s)
		{
			a[ch-'a']+=1;
		}
		int sum = 0;
		int flag = 0;
		for (int i = 0; i < 26; ++i)
		{
			if(a[i]==1)
			{
				sum++;
			}
			if(a[i]>1)
			{
				flag = 1;
				break;
			}
			if(sum && sum!=s.length() && (a[i]==0))
			{
				flag=1;
				break;
			}
		}

		if(flag==1)
		{
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}
	}
}
