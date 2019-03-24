#include <bits/stdc++.h>
using namespace std;

int a[]={0, 36, 21, 16, 31, 58, 41, 26, 59, 53, 97};

void heapify(int a[], int n, int i)
{
	if(i<=n && 2*i<=n)
	{
		int largest = i, left = 2*i, right = 2*i +1 ;	
		int index=((left<=n?a[left]:0)>(right<=n?a[right]:0))?left:right; //left and right mese maximum 
		if(a[largest]>a[index]) return;
		if(largest != index && a[largest]<a[index]);
		{
			swap(a[index],a[largest]);
			heapify(a,n,index);
		}
	}

	// printf("%d\n", largest);
}

void heapsort(int a[], int n)
{
	for(int i=n/2; i>0; i--)
	{
		// printf("i= %d\n", i);
		heapify(a,n,i);
	}

	for(int i=n;i>0;i--)
	{
		if(a[1]<a[i])
			break;
		swap(a[1],a[i]);
		heapify(a,i-1,1);
		
	}
}

int main()
{
	heapsort(a, 10);
	for(int i=1; i<=10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}