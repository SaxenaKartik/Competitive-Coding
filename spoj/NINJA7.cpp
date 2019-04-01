#include <bits/stdc++.h>
using namespace std;

long long int limit;
// vector <long long int> dp;

void solve(long long int mask,long long int *arr,long long int *arr1)
{
	// cout<<limit;
	while(mask<=limit)
	{	

		// cout<<"mask = "<<mask<<endl;

		if(mask==0) arr1[mask]=0;
		
		else if(!(mask&(mask-1)))
		{
			// cout<<"mask "<<mask<<endl;
			arr1[mask]=arr[(long long int)log2(mask)];	
		} 
		else
		{
			for(long long int i=0;i<mask;i++)
			{
				if(mask&(1<<i))
					arr1[mask]+=arr1[mask&(1<<i)];
			}
		}
		mask++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int t=0;
	cin>>t;
	while(t--)
	{
		long long int n=0;
		cin>>n;
		long long a[n],b[n];
		limit=(1<<n)-1;
		for(long long int i=0;i<n;i++)
		{
			cin>>a[i];
		}

		for(long long int i=0;i<n;i++)
		{
			cin>>b[i];
		}

		/*for(int i=0;i<n;i++)
		{
			cout<<b[i];
		}
*/
		long long int mask=0;
		long long a1[limit+1],b1[limit+1];
		for(int i=0;i<limit+1;i++)
		{
			a1[i]=0;
			b1[i]=0;
		}

		solve(mask,a,a1);

		mask=0;

		solve(mask,b,b1);

		/*for(int i=0;i<(int)pow(2,n);i++)
		{
			cout<<a1[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<(int)pow(2,n);i++)
		{
			cout<<b1[i]<<" ";
		}
		cout<<endl;*/
		long long int k;
		for(k=limit;k>=0;k--)
		{
			if(a1[k]>=b1[k])
				break;
		}

		long long int count=0;

		for(long long int i=0;i<n;i++)
		{
			if(k&(1<<i)) count++;
		}

		cout<<count<<endl;
	}
}/**/