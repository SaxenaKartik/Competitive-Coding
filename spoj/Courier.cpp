#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,b;
		cin>>n>>m>>b;
		int a[n][n];

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				a[i][j]=100000;
			}
		}

		for(int i=0;i<m;i++)
		{	

			int x,y,k;
			cin>>x>>y>>k;
			a[x-1][y-1]=k;
			a[y-1][x-1]=k;
		}

		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}*/


		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i==j)
					{
						a[i][j]=0;
					}
					else if(a[i][j]>a[i][k]+a[k][j])
					{
						a[i][j]=a[i][k]+a[k][j];
						a[j][i]=a[i][k]+a[k][j];
					}
				}
			}
		}

		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}*/

		int z;
		cin>>z;

		int bit[z];
		int p[z][z];
		for(int i=0;i<z;i++)
		{
			for(int j=0;j<z;j++)
			{	
				bit[i]=1;
				cin>>p[i][j];
			}
		}

		int parcels=0;
		for(int i=0;i<z;i++)
		{
			parcels+=p[i][2];
		}

		// cout<<parcels;
		int sum=0;
		int i,m0,m1,m2,curr=b,next,number;
		
		while(parcels)
		{
			m0=100000;
			int current;
			for(i=0;i<z;i++)
			{
				if(a[curr-1][p[i][0]-1]<m0 && bit[i])
				{
					m0=a[curr-1][p[i][0]-1];
					current=p[i][0];
					next=p[i][1];
					number=p[i][2];
				}
			}

			curr=current;
			// cout<<"curr= "<<curr;
			for(int i=0;i<z;i++)
			{
				if(curr==p[i][0] && next==p[i][1])
				{
					bit[i]=0;
				}
			}
			
			// cout<<"m0= "<<m0<<endl;
			// break;
			
			sum+=m0;

			m1=(a[curr-1][next-1])*((2*number)-1);
			// cout<<"m1= "<<m1<<endl;
			curr=next;
			sum+=m1;
			parcels-=number;

		}

		sum+=a[curr-1][b-1];

		cout<<sum<<endl;
	}
}