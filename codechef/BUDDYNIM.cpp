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
int a[105];
int b[105];

int32_t main()
{
	fast_io();
	cin>>t;
	while(t--)
	{
		int n,m,suma=0, sumb=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			suma+=a[i];
		}

		for(int i=1;i<=m;i++)
		{
			cin>>b[i];
			sumb+=b[i];
		}

		sort(a+1,a+1+n, greater <int>());
		sort(b+1, b+1+m, greater <int>());

		while(a[n]==0 &&  n>0) n--;
		while(b[m]==0 && m>0) m--;

		int flag = 0;

		if(suma==sumb)
		{
			for(int i=1;i<=n && i<=m ;i++)
			{
				if(a[i]!=b[i])
				{
					cout<<"Alice"<<endl;
					flag=1;
					break;
				}
			}

			if(flag==0)
			{
				cout<<"Bob"<<endl;
			}
		}
		else
		{
			cout<<"Alice"<<endl;
		}
	}
	return 0;
}
