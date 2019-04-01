#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char a,b,c,d,e,f;
		cin>>a>>b>>c;
		cin>>d>>e>>f;

		// int countb=0, counto=0;

		
		if((a=='o' || d=='o') && (b=='b' || e=='b') && (c=='b' || f=='b'))
		{
			printf("yes\n");
		}
		else if((a=='b' || d=='b') && (b=='o' || e=='o') && (c=='b' || f=='b'))
		{
			printf("yes\n");
		}
		else if((a=='b' || d=='b') && (b=='b' || e=='b') && (c=='o' || f=='o'))
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}

	return 0;
}