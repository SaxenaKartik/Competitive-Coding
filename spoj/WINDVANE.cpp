#include <bits/stdc++.h>
using namespace std;

int m,n,c;
int BIT[1005][1005];
int eq[1005][1005];

void update(int x, int y, int val)
{
	for(;x<=n;x+=x&-x)
	{
		for(int y1=y;y1<=m ;y1+=y1&-y1)
		{
			BIT[x][y1]+=val;
			//BIT[x][y]%=4;
			//BIT[x][y]+=1;
		}
	}
}

int query(int x, int y)
{
	int sum=0;
	int val=eq[x][y];
	for(;x>0;x-=x&-x)
	{
		for(int y1=y;y1>0;y1-=y1&-y1)
		{
			sum+=BIT[x][y1];
		}
	}
	return sum+val; //range update only works for initial value 0 in BIT (or in this case?)
}

/*void update1(int x, int y, int val)
{
	for(;x<=n;x+=x&-x)
	{
		for(int y1=y;y1<=m ;y1+=y1&-y1)
		{
			BIT[x][y1]+=val;
			
		 }
	}
}*/

int main()
{
	char ch;
	scanf("%d %d", &n, &m);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='N')
			{
				// update(i,j,1);
				eq[i][j]=1;
			}
			else if(ch=='E')
			{
				// update(i,j,2);
				eq[i][j]=2;
			}
			else if(ch=='S')
			{
				// update(i,j,3);
				eq[i][j]=3;
			}
			else if(ch=='W')
			{
				// update(i,j,4);
				eq[i][j]=4;
			}
		}
	}

	scanf("%d", &c);

	int x1,y1,x2,y2,d,val;
	int ans;

	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",query(i,j)-query(i-1,j)-query(i, j-1)+query(i-1, j-1));
		}
		printf("\n");
	}*/
	
	char a;
	while(c--)
	{
		cin>>a;
		// cout<<a;
		if(a=='C')
		{
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &d);
			// printf("%d\n", d);
			if(d==0)
			{
				val=1;
			}
			else
			{
				val=-1;
			}

			update(x1,y1,val);
			update(x1, y2+1, -val);
			update(x2+1, y1, -val);
			update(x2+1,y2+1,val);
		}
		else if (a=='D')
		{
			scanf("%d %d", &x1, &y1);
			// printf("%d\n",query(x1,y1)-query(x1-1,y1)-query(x1,y1-1)+query(x1-1,y1-1));
			int val=query(x1,y1);
			int mod=val%4;
			if(mod<0)
				mod+=4;
			if (mod == 1)
                printf("N\n");
            else if (mod == 2)
                printf("E\n");
            else if (mod == 3)
                printf("S\n");
            else if (mod == 0)	
				printf("W\n");

			/*for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					printf("%d ",query(i,j));
				}
				printf("\n");
			}*/

		}
	}
	return 0;
}