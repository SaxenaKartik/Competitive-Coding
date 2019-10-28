#include <bits/stdc++.h>
using namespace std;
char a[110][110];
int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};
int n,m,tx,ty,k;
// queue<pair <int, int> >q;
bool vis[110][110];

bool issafe(int x,int y){
	if(x>0 && x<=n && y>0 && y<=m)
	{
		return true;
	}
	return false;
}

bool dfs(int x,int y,int steps)
{

	if(vis[x][y])
	{
		if(x==tx && y==ty && steps>=k)
		{
			return 1;
		}
		return 0;
	}

	vis[x][y]=1;

	int cx,cy;
	for(int i=0;i<4;i++)
	{
		cx=x+X[i];
		cy=y+Y[i];

		if(issafe(cx,cy) && a[cx][cy]=='.')
		{
			if(dfs(cx,cy,steps + 1))   
            	return 1;
		}
	}
	vis[x][y]=0;
	return 0;
}

int main()
{
	// int n,m;
	cin>>n>>m;
	cin>>k;
	cin>>tx>>ty;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	// memset(vis,false,sizeof(vis));

	// q.push(make_pair(x,y));
	// vis[x][y]=true;
	// q.push(make_pair(-1,-1));

	/*while(k--)
	{
		int cx,cy;
		pair<int , int> node=q.front();
		q.pop();
		cx=node.first;
		cy=node.second;
		// vis[cx][cy]=true;*/
		
	// }

	/*int x1,y1;

	x1=q.front().first;
	y1=q.front().second;

	if(x1==x && y1==y)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}*/

	if(dfs(tx,ty,0))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

}