#include <bits/stdc++.h>
using namespace std;
#define ll long long 

string n;
// map<int,ll>v;
ll dp[50007];

ll acode(string s)
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	int j,n=s.length();
	for(int i=1;i<n;i++)
	{
		j=(s[i-1]-'0')*10 + (s[i]-'0');

		if(s[i]-'0') dp[i]=dp[i-1];
		if(j>9 && j<27)
		{
			if(i==1)
				dp[i]=dp[i]+1;
			else
				dp[i]=dp[i]+dp[i-2];
		}
	}

	return dp[n-1];	
}

int main()
{
	while(true)
	{
		cin>>n;
		if(n!="0")
		{
			printf("%lld\n",acode(n));
			continue;
		}
		else
			return 0;
	}
}