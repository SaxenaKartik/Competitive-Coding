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

int32_t main()
{
	fast_io();
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n+1];
		for(int i=1; i<=n;i++)
		{
			int x;
			cin>>x;
			arr[i] = x;
		}

		int book[n+1];
		int counter[n+1];
		// memset(counter, 0, n+1);
		for(int i=1;i<=n;i++)
		{
			counter[i] = 1;
			// cout<<counter[i]<<endl;
		}
		// debug(counter);
		for(int i=1;i<=n;i++)
		{
			book[i] = arr[i];
		}
		// int z = 0;
		while(true)
		{
			int flag = 0;
			for(int i=1;i<=n;i++)
			{
				if(book[i] != i)
				{
					book[i] = arr[book[i]];
					counter[i]+=1;
					flag = 1;
				}
			}
			if(flag == 0)
			{
				break;
			}
			// debug(book,counter,arr);	
			// for(int i=1;i<=n;i++)
			// {
			// 	cout<<book[i]<<" ";
			// }
			// cout<<endl;
			// for(int i=1;i<=n;i++)
			// {
			// 	cout<<counter[i]<<" ";
			// }
			// cout<<endl;
			// z++;
		}

		for(int i = 1;i<=n; i++)
		{
			cout<<counter[i]<<" ";
		}
		cout<<endl;	
	}
}