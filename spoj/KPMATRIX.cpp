#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define SIZE 260
int arr[SIZE][SIZE];
// int s[SIZE][SIZE];
int bigarr[SIZE*3];
int n,m;
int sum[SIZE], sum_A[SIZE], sum_B_1[SIZE];
int BIT[SIZE*3];

int find(int value, int start, int end)
{
	while(start<=end)
	{
		int mid=start+end>>1;
		if(bigarr[mid]==value) return mid;
		else if(bigarr[mid]<value) start=mid+1;
		else end=mid-1;
	}
	return -1;
}

void update(int x, int n1)
{
	for(;x<=n1;x+=x&-x)
	{
		BIT[x]++;
	}
}

int query(int x)
{
	int res=0;
	for(;x>0;x-=x&-x)
	{
		res+=BIT[x];
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	// ll x;

	for(int j=1;j<=m;j++)
		arr[0][j]=0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			/*scanf("%lld", &x);
			update(i,j,x);*/
			scanf("%d", &arr[i][j]);
			arr[i][j]=arr[i-1][j]+arr[i][j]; //calculating prefix column sum
		}	
	}

	int A,B;
	scanf("%d %d", &A, &B);

	/*for(int j=1; j<=m;j++) printf("%d ", arr[0][j]);
        printf("\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;*/

	ll res=0;

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			//storing all possible values of sum, sum-A & sum-B-1 in bigarr
			int count=1;
			sum[0]=0;
			sum_A[0]=sum[0]-A;
			sum_B_1[0]=sum[0]-B-1;
			bigarr[count++]=sum[0];
			bigarr[count++]=sum_A[0];
			bigarr[count++]=sum_B_1[0];

			for(int k=1;k<=m;k++)
			{
				sum[k]=sum[k-1]+arr[j][k]-arr[i-1][k]; //calculating prefix row sum
				sum_A[k]=sum[k]-A;
				sum_B_1[k]=sum[k]-B-1;
				bigarr[count++]=sum[k];
				bigarr[count++]=sum_B_1[k];
				bigarr[count++]=sum_A[k];
			}

			/*for(int i=1;i<count;i++)
			{
				printf("%d ", bigarr[i]);
			}

			printf("\n");*/

			// break;

			sort(bigarr+1, bigarr+count);

			//removing duplicate values from bigarr

			int size=2;
			for(int i=2;i<count;i++)
			{
				if(bigarr[i]==bigarr[i-1]) continue;
				bigarr[size++]=bigarr[i];
			}

			size--;

			/*for(int k=1;k<=size;k++)
			{
				printf("%d ", bigarr[k]);
			}

			printf("\n");*/


			memset(BIT, 0 , sizeof(BIT));

			update(find(sum[0],1,size),size);

			/*printf("query : ");
            for(int p=1;p<=size;p++)
            {
                printf(" %d ", query(p));
            }*/

            // printf("\n");

			for(int i=1; i<=m;i++)
			{
				int e=find(sum_A[i],1,size);
				int s=find(sum_B_1[i],1,size);
				res+=query(e)-query(s);
				update(find(sum[i],1,size),size);
			}
		}
	}

	printf("%lld\n", res);

	return 0;
}
