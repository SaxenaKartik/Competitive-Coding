#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 100000;
 
int n;
string st;
vector<pair<long long, long long> > v;
vector<long long> nd;
 
int t[N];
 
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
 
int sum(int r)
{
    int res = 0;
    for (; r >= 0; r = (r&(r + 1)) - 1)
        res += t[r];
    return res;
}
 
void inc(int i, int delta)
{
    for (; i < n; i = (i | (i + 1)))
        t[i] += delta;
}
 
inline void parse(string &st,pair<long long, long long>&res)
{
    res.first = func(st);
    reverse(st.begin(), st.end());
    res.second = func(st);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
 
    cin >> n;
    pair<long long, long long> P;
 
    for (int i = 1; i <= n; i++)
    {
        cin >> st;
        parse(st,P);
        v.push_back(P);
        nd.push_back(P.second);
    }
 
    sort(nd.begin(), nd.end());
 
    sort(v.begin(), v.end());
 
    long long ans = 0;
 
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int whr = lower_bound(nd.begin(), nd.end(), v[i].second) - nd.begin();
        ans += sum(whr);
        inc(whr, 1);
    }
 
    cout << ans << endl;
 
    return 0;
}