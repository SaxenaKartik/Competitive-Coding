#include <bits/stdc++.h>
using namespace std;

// stack<pair<int, int> >st;
int X[]={0, 0, 1, -1, 1, 1, -1, -1};
int Y[]={1, -1, 0, 0, 1, -1, 1, -1};
bool vis[101][101];
char a[101][101];
char sent[11]={'A','L','L','I','Z','Z','W','E','L','L'};
int r,c;

bool issafe(int x,int y)
{
	if(x>=0 && y>=0 && x<r && y<c)
		return true;
	return false;
}
	

string dfs(int x,int y, int count)
{
	string s;
	vis[x][y]=true;
	if(count==9) return "YES";
	 
	else
	{    
	    int cx,cy;
		// cout<<cx<<cy<<endl;	
		for(int i=0;i<8;i++)
		{
			cx=x+X[i];
			cy=y+Y[i];
			// cout<<cx<<cy<<endl;
			if(issafe(cx,cy))
			{
				if(a[cx][cy]==sent[count+1] && !vis[cx][cy]){
					vis[cx][cy]=true;
					s=dfs(cx,cy,count+1);
					if(s=="YES"){
						return s;
						vis[cx][cy]=false;
					}
					
				}

			}
		}
	}
	vis[x][y]=false;
	return "NO";	
}


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int r1,c1;
		cin>>r1>>c1;
		r=r1;
		c=c1;
		
		memset(vis,false,sizeof(vis));

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>a[i][j];
			}
		}


		bool flag=false;


		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(a[i][j]=='A'&& dfs(i,j,0)=="YES"){
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}


		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
		// cout<<st.top().first<<st.top().second<<endl;
	}
}