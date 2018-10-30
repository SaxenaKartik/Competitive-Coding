//using prefix sum

/*error in case
	
	7 28
	24 2 1 23 2 1 1 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 300005

int n;
ll m;

ll a[SIZE];
ll pre[SIZE];

int main()
{
	scanf("%d %lld",&n, &m);
 		
	for(int i=0;i<n;i++)
	{
		scanf("%lld", &a[i]);
	}

	ll sum=0;

	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		pre[i]=sum;
	}

	ll k,s,ans;
	k=lower_bound(pre,pre+n,m)-pre;

	// printf("%lld\n", k);


	if(*find(a,a+n,m)==m) // if value is found in array itself
	{
		ans=m;	
	}
	else if(k==n) 	//if all values of prefix sum are smaller
	{
		ans=pre[k-1];
	}
	else if(pre[k]>m) //if values are bigger in prefix sum then we try to reach the closest value 
	{
		ll s=lower_bound(pre,pre+n,pre[k]-m)-pre;
		// printf("%\n");
		ans=pre[k]-pre[s];
	}
	else //if value is found in prefix sum
	{	
		// printf("here\n");
		ans=pre[k];
	}

	printf("%lld\n", ans);
}