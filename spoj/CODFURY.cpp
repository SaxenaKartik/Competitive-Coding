#include <bits/stdc++.h>
using namespace std;
#define SIZE 50005

int a[SIZE];

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int p,m;
		scanf("%d %d", &p, &m);

		for(int i=0;i<p;i++)
		{
			scanf("%d", &a[i]);
		}

		int i=0,sum=0,length=0,minsum=1001, maxlength=0;

		for(int j=0;j<p;j++)
		{
			sum+=a[j];
			length++;
			while(sum>m)
			{
				sum-=a[i];
				length--;
				i++;
			}
			if(maxlength<length)
			{
				maxlength=length;
				minsum=sum;
			}
			else if(maxlength==length)
			{
				if(minsum>sum)
				{
					minsum=sum;
				}
			}
		}

		printf("%d %d\n",minsum, maxlength);
	}
}