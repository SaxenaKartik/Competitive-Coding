#include <bits/stdc++.h>

using namespace std;

// Input macros

#define si(n)                       scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
 
// Useful constants

#define INF                         (int)1e9
#define EPS                         1e-9
#define MOD1                        1000000009
#define MOD2                        1000000007

// Useful hardware instructions

#define bitcount                    __builtin_popcount
#define gcd                         __gcd
 
// Useful container manipulation / traversal macros

#define forI(i,n)                   for(i=0  ; i< n ;i++)
#define forD(i,n)                   for(i=n-1; i>=0 ;i--)  
#define forall(i,a,b)               for(i=a  ; i<=b ;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
 
// Some common useful functions

#define MAX(a,b)                     ( (a) > (b) ? (a) : (b))
#define MIN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
 
// datatypes

#define ll                           long long int
#define ull                          unsigned long long
#define ui                           unsigned int
#define us                           unsigned short
#define vi                           vector<int>
#define pii                          pair<int,int>
#define gc                           getchar_unlocked
#define pc                           putchar_unlocked 

// Faster Input/Output

inline void get_int(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline void get_long(ll &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void print_int(int X)
{
    if(X<0) { pc('-');  X=-X;  }
    int Len=0,Data[20];
    while(X) { Data[Len++]=X%10; X/=10; }
    if(!Len) Data[Len++]=0;
    while(Len--) pc(Data[Len]+48);
    pc('\n');
}
inline void print_long(long long int X)
{
    if(X<0) { pc('-');  X=-X;  }
    int Len=0,Data[20];
    while(X) { Data[Len++]=X%10; X/=10; }
    if(!Len) Data[Len++]=0;
    while(Len--) pc(Data[Len]+48);
    pc('\n');
}

// Main Function
#define MAXN 505
ll BIT1[MAXN][MAXN],BIT2[MAXN][MAXN];
ll N,M;
void init()
{
    ll i,j;
    forI(i,MAXN)
    {
        forI(j,MAXN)
        {
            BIT1[i][j]=BIT2[i][j]=0;
        }
    }
}
void update(ll BIT[][505],ll x,ll y,ll val)
{
    while(y <= M)
    {
        BIT[x][y]+=val;
        y += (y & -y);
    }
}
/*void update_pt(ll x,ll y,ll v)
{
    update(BIT1,x,y,v);
    update(BIT2,x,y,v*(y-1));
}*/
void update_range(ll x,ll y1,ll y2,ll v)
{
    update(BIT1,x,y1,v);
    update(BIT1,x,y2+1,-v);
    update(BIT2,x,y1,v*(y1-1));
    update(BIT2,x,y2+1,-v*y2);
}
void update_range2D(ll x1,ll y1,ll x2,ll y2,ll v)
{
    ll i;
    forall(i,x1,x2)
    {
        update_range(i,y1,y2,v);
    }
}
ll read(ll BIT[][505],ll x,ll y)
{
    ll sum = 0;
    while(y>0)
    {
        sum+=BIT[x][y];
        y-=(y & -y);
    }
    return sum;
}
ll query(ll x,ll y)
{
    return read(BIT1,x,y)*y-read(BIT2,x,y);
}
ll query_range(ll x,ll y1,ll y2)
{
    return query(x,y2)-query(x,y1-1);
}
ll query_range2D(ll x1,ll y1,ll x2,ll y2)
{
    ll i,sum=0;
    forall(i,x1,x2)
    {
        sum+=query_range(i,y1,y2);
    }
    return sum;
}
int main()
{
    ll i,j,q,num;
    init();
    get_long(N);get_long(M);
    forI(i,N)
    {
        forI(j,M)
        {
            get_long(num);
            update_range2D(i+1,j+1,i+1,j+1,num);
        }
    }
    get_long(q);
    ll ch,x1,y1,x2,y2,v;

    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            printf("%lld ",query_range2D(i+1,j+1,i+1,j+1));
        }
        printf("\n");
    }*/

    while(q--)
    {   
        get_long(ch);
        if(ch==1)
        {
            get_long(x1);get_long(y1);get_long(x2);get_long(y2);get_long(v);
            update_range2D(x1,y1,x2,y2,v);
        }
        else
        {
            get_long(x1);get_long(y1);get_long(x2);get_long(y2);
            print_long(query_range2D(x1,y1,x2,y2));
            // for(int i=0;i<N;i++)
            // {
            //     for(int j=0;j<M;j++)
            //     {
            //         printf("%lld ",query_range2D(i+1,j+1,i+1,j+1));
            //     }
            //     printf("\n");
            // }
        }
    }
    return 0;
}