/*why use BIT?

1. time limit is pretty small
2. the strings are atmost of 10 letters
3. we can see that we need to find inverses
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll n;
ll BIT[100000];

vector<pair<ll,ll> >v;
vector<ll> a;

long long func(string &st)
{
    long long res = 0;
    for (int i = 0; i < st.size(); i++)
    {
        res = res * 32 + st[i] - 'a' + 1;
    }
    for (int i = st.size(); i <= 10; i++)
        res = res * 32;
    return res;
}

/*bool comp(const pair<ll,ll> &p, const pair<ll,ll> &q)
{
	return p.first<q.first;
}*/

void update(int x,int val)
{
	for(;x<=n;x+=x&-x)
	{
		BIT[x]+=val;
	}
}

ll sum(int x)
{
	ll sum=0;
	for(;x>0;x-=x&-x)
	{
		sum+=BIT[x];
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ll n;
	cin>>n;

	string s,r;
	for(int i=0;i<n;i++)
	{
		cin>>r;
		s=r;
		reverse(r.begin(),r.end());
		v.push_back(make_pair(func(s),func(r)));
		a.push_back(v[i].second);
	}

	sort(v.begin(),v.end());
	sort(a.begin(),a.end());

	for(int i=0;i<n;i++)
	{
		v[i].second=lower_bound(a.begin(),a.end(),v[i].second)-a.begin()+1;
	}
	
	for(int i=1;i<=n;i++)
	{
		BIT[i]=0;
	}

	ll inverses=0;

	for(int i=n-1;i>=0;i--)
	{
		inverses+=sum(v[i].second-1);
		update(v[i].second,1);
	}
	printf("%lld\n", inverses);
}