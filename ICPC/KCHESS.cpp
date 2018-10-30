#include<bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define ll long long

ll n,t,x,y,a,b;
int X[]={1,2,-1,-2,-1,-2,1,2};
int Y[]={2,1,2,1,-2,-1,-2,-1};
int X1[]={1,0,1,-1,0,-1,-1,1};
int Y1[]={0,1,1,0,-1,1,-1,-1};
vector<pair<int,int> > posknight;
vector<pair<int, int> > poscov;

int32_t main()
{
	fast_io();
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			
			cin>>x>>y;
			posknight.push_back({x,y});
		}

		cin>>a>>b;
		

		for(int i=0;i<n;i++)
		{
			poscov.push_back(make_pair(posknight[i].first,posknight[i].second));

			for(int j=0;j<8;j++)
			{
				poscov.push_back(make_pair(posknight[i].first+X[j],posknight[i].second+Y[j]));
			}
		}

		// sort(poscov.breakegin(), poscov.end());

		int flag=0;
		for(int i=0;i<8;i++)
		{
			flag=0;
			pair<int, int> p=make_pair(a+X1[i],b+Y1[i]);
			if(find(poscov.begin(), poscov.end(), p)==poscov.end())
			{
				// cout<<p.first<<" "<<p.second<<endl;
				flag=1;
				break;
			}
		}

		// printf("here\n");
		if(flag==1)
		{
			cout<<"NO"<<endl;

		}
		else
		{
			cout<<"YES"<<endl;
		}
	}

}


   /* #include <vector>
    #include <iostream>
    #include <algorithm>
    int main()
    {
      std::vector<std::pair<int, int>> v = {{1,2}, {3,4}, {5,6}};
      auto p = std::make_pair(3, 4);
     
      if(std::find(v.begin(), v.end(), p) != v.end())
          std::cout << "yes\n";
    }*/