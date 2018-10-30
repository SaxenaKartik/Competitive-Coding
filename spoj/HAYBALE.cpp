//Using BIT

#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
long long n,k;
long long BIT[MAXN];
long long arr[MAXN];

void update(int x,int val)
{
	for(;x<=n;x+= x&-x)
		BIT[x]+=val;
}

int query(int x)
{
	int sum=0;
	for(;x>0;x-= x&-x)
		sum+=BIT[x];
	return sum;

}

int main()
{
	scanf("%lld %lld",&n,&k);

	for(long long i=0;i<k;i++)
	{
		long long a,b;
		scanf("%lld %lld",&a,&b);
		update(a,1);
		update(b+1,-1);
	}
	long long k=0;
	for(long long int i=1;i<=n;i++)
	{
		arr[k++]=query(i);
		// cout<<arr[k-1]<<endl;
	}

	/*for(int i=0;i<n;i++)
	{	
		cout<<arr[i]<<" ";
	}*/
	
	sort(arr,arr+n);
	/*cout<<endl;
	for(int i=0;i<n;i++)
	{	
		cout<<arr[i]<<" ";
	}*/
 	printf("%lld\n",arr[n/2]);
	return 0;
	
}