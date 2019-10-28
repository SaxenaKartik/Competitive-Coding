#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#else
#define debug(...) 0
#endif

#define mp make_pair
#define fi first
#define se second

typedef long long int ll;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> pii;


priority_queue<ll>s;

struct item
{
    ll x,y,pos;
}a[500100];

bool cmp(item a, item b)
{
    return a.x<b.x;
}

int32_t main()
{

    int t;
    cin>>t;
    while(t--)
    {
        // int ans=0;
        ll n,k,ans=0;
        memset(a,0,sizeof(a));
        s = priority_queue <ll>();
        cin>>n>>k;
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i].x,&a[i].y);
            a[i].pos=i;
        }
        sort(a+1,a+n+1,&cmp);
        for(ll i=1;i<=n;i++)
        {
            if((int)s.size()<k)
                s.push(-a[i].y);
            else if(-s.top()<a[i].y)
                s.pop(),s.push(-a[i].y);
            if(ans<-s.top()-a[i].x&&(int)s.size()==k)
                ans=-s.top()-a[i].x;
                // l=a[i].x;
        }
        cout<<ans<<endl;
    }
    /*if(ans==0)
    {
        for(ll i=1;i<=k;i++)
            printf("%lld ",i);
        return 0;
    }
    for(ll i=1;i<=n&&k;i++)
        if(a[i].x<=l&&l+ans-1<=a[i].y)
            printf("%lld ",a[i].pos),k--;*/
}