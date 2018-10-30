//using modified kadane
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 300005

int n;
ll m;

ll a[SIZE];

int main()
{
	scanf("%d %lld",&n, &m);
 		
	for(int i=0;i<n;i++)
	{
		scanf("%lld", &a[i]);
	}

	int i,j;
	ll sum=0,max=0;
	i=0;j=0;

	for(int j=0;j<n;j++)
	{
		sum+=a[j];
		if(sum>m)
		{
			// printf("here\n");
			while(sum>m)
			{	
				sum-=a[i];
				i++;
			}

		}	
		// printf("%lld\n", sum);

		if(max<sum)
		{
			max=sum;
			// printf("%lld\n",max );
		}
	}

	printf("%lld\n", max);
}