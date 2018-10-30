#include<bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define ll long long

ll n,m,t,h,c,a,b;
map<ll,ll> colours;
// int X[]={1,2,-1,-2,-1,-2,1,2};
// int Y[]={2,1,2,1,-2,-1,-2,-1};
// int X1[]={1,0,1,-1,0,-1,-1,1};
// int Y1[]={0,1,1,0,-1,1,-1,-1};
vector<pair<ll,ll> > student;
// vector<pair<int, int> > poscov;

int32_t main()
{
	fast_io();
	cin>>t;
	while(t--)
	{
		for(int i=0;i<colours.size();i++)
		{
			colours[i]=0;
		}

		cin>>n>>m;
		int count=0;
		for(int i=0;i<n;i++)
		{	
			cin>>h;
			student.push_back({h,0});
		}

		// cin>>a>>b;
		
		for(int i=0;i<n;i++)
		{	
			cin>>c;
			student[i].second=c;
		}

		/*for(int i=0;i<n;i++)
		{
			cout<<student[i].first<<" "<<student[i].second<<endl;
		}*/

		ll max=-1;
		ll maxcolour=-1;

		// ll current;


		/*for(int i=0;i<n;i+=1)
		{
			colours.push_back(student[i].second);
		}
*/	
		ll current;
		ll last;

		printf("%d\n", count);

	}

}
