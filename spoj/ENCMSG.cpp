#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		string s;
		cin>>s;

		if(n%2==0)
		{
			for(int i=1;i<n;i+=2)
			{
				char ch=s[i];
				s[i]=s[i-1];
				s[i-1]=ch;
			}
		}
		else
		{
			for(int i=1;i<n-1;i+=2)
			{
				char ch=s[i];
				s[i]=s[i-1];
				s[i-1]=ch;
			}
		}

		for(int i=0;i<n;i++)
		{
			char ch=s[i];
			ch=219-ch;
			s[i]=ch;
		}

		cout<<s<<endl;
	}
	return 0;
}