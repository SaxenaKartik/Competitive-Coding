#include <bits/stdc++.h>
using namespace std;
#define ll long long 

string a,b;
ll dp[2005][2005];

int main()
{
	int	t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		memset(dp,0,sizeof(dp));

		for(int i=1;i<=a.length();i++)
		{
			dp[i][0]=i;
		}

		for(int i=1;i<=b.length();i++)
		{
			dp[0][i]=i;
		}

		for(int i=1;i<=a.length();i++)
		{
			for(int j=1;j<=b.length();j++)
			{	
				if(a[i-1]!=b[j-1])
					dp[i][j]=1+dp[i-1][j];
				else
					dp[i][j]=dp[i-1][j-1];
			}
		}

		printf("%lld\n",dp[a.length()][b.length()]);
	}
}