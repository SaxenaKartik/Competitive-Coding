#include <bits/stdc++.h>
using namespace std;


#define MAXR 101
#define MAXC 101
#define MAXDIRTY 101 
#define MAXMASK 2048
#define INF INT_MAX



int dist[MAXR][MAXC][MAXDIRTY];
int dp[MAXDIRTY][MAXMASK];

vector <pair<int,int> > dirty;
int len,limit,r,c;

char arr[21][21];

int X[]={-1,0,0,1};
int Y[]={0,1,-1,0};


bool safe(int x, int y)
{
    if (x >= r or y>= c or x<0 or y<0)
       return false;
    if (arr[x][y] == 'x')
       return false;
    return true;
}


void bfs(int idx)
{
	bool vis[21][21];
	memset(vis,false,sizeof(vis));

	int cx=dirty[idx].first;
	int cy=dirty[idx].second;

	queue <pair<int, int > >pq;
	pq.push({cx,cy});

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			dist[i][j][idx]=INF;
		}
	}

	vis[cx][cy]=true;
	dist[cx][cy][idx]=0;

	while(!pq.empty())
	{
		auto x=pq.front();
		pq.pop();
		for(int i=0;i<4;i++)
		{	
			cx=x.first+X[i];
			cy=x.second+Y[i];
			if(safe(cx,cy))
			{
				if(vis[cx][cy])
					continue;
				vis[cx][cy]=true;
				dist[cx][cy][idx]=dist[x.first][x.second][idx]+1;
				pq.push({cx,cy});
			}
		}
	}

}


int solve(int idx, int mask)
{
    // goal state
    if (mask == limit)
       return 0;
 
    // if already visited state
    if (dp[idx][mask] != -1)
       return dp[idx][mask];
 
    int ret = INT_MAX;
 
    // state transiton relation
    for (int i = 0;i<len;i++)
    {
        if ((mask & (1<<i)) == 0)
        {
            int newMask = mask | (1<<i);
            ret = min( ret, solve(i, newMask)
                + dist[dirty[i].first][dirty[i].second][idx]);
        }
    }
 
    // adding memoization and returning
    return dp[idx][mask] = ret;
}


int main()
{
	int w,h;
	
	while(true){
		cin>>w>>h;
		r=h;
		c=w;
		if(w==0 && h==0)
			break;
		else
		{
			memset(dp, -1, sizeof(dp));
			dirty.clear();	
			int x,y;
			for(int i=0;i<h;i++)
			{
				for(int j=0;j<w;j++)
				{
					cin>>arr[i][j];
					if(arr[i][j]=='o')
					{
						x=i;
						y=j;
					}
					if(arr[i][j]=='*')
						dirty.push_back({i,j});
				}
			}

			dirty.insert(dirty.begin(),{x,y});

			len=dirty.size();

			limit=(1<<len)-1;

			for(int i=0;i<len;i++)
			{
				bfs(i);
			}

			/*for(int k=0;k<len;k++)
			{
				
			}*/
			int ans=solve(0,1);
			if (ans >= INF)
    	   	 	cout << "-1" << endl;
    		else
        		cout << ans << endl;	
		}

	}
	return 0;
}