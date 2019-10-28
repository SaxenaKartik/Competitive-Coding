
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
typedef long long int ll;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
char s[510][510];
int32_t main()
{
    fast_io();
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
                cin>>s[i][j];
        }
    }

    if(n<=2)
    {
        cout<<0<<endl;
        return 0;
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
               if(s[i][j]=='X')
                {
                        if(s[i-1][j-1]=='X'&&s[i-1][j+1]=='X'&&s[i+1][j-1]=='X'&&s[i+1][j+1]=='X')
                        {
                                count++;
                        }
                }
        }
    }
    cout<<count<<endl;
}