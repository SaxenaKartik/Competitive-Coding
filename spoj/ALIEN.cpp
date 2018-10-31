#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100005 

ll a,b;
ll arr[SIZE];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld", &a, &b);
		// memset(arr,0,sizeof(arr));
		for(int i=0;i<a;i++)
		{
			scanf("%lld", &arr[i]);
		}

		int sum=0,length=0,minsum=101, maxlength=0;
		int i=0;
		for(int j=0;j<a;j++)
		{
			sum+=arr[j];
			length++;
			while(sum>b)
			{	
				sum-=arr[i];
				length--;
				i++;
			}
			if(maxlength<length)
			{
				maxlength=length;
				minsum=sum;
			}
			else if(length==maxlength)
			{
				// printf("here\n");
				if(minsum>sum)
				{
					minsum=sum;
				}
			}
		}

		printf("%d %d\n", minsum,maxlength);
	}
	return 0;
}