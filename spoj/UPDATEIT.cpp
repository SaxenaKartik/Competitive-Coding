#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005

long long BIT[MAXN];
int t,n,u,l,r,val,q,id;
long long a[MAXN];


inline void superFastRead (int *a)
{
    char c = 0;
    while(c<33)
    c = fgetc(stdin);
    *a = 0;
    while(c>33)
    {
               *a = *a*10 + c - '0';
               c = fgetc(stdin);
    }
}

void update(long long x,long long val)
{
	for(;x<=n;x+= x&-x)
	{
		BIT[x]+=val;
	}
}

long long query(long long x)
{
	long long sum=0;
	for(;x>0;x-= x&-x)
	{
		sum+=BIT[x];
	}

	return sum;
}

int main()
{	superFastRead(&t);
	while(t--){
		superFastRead(&n);
		superFastRead(&u);
		memset(BIT,0,sizeof(BIT));
		for(long long i=0;i<u;i++){
			superFastRead(&l);
			superFastRead(&r);
			superFastRead(&val);
			l++;r++;
			update(l,val);
			update(r+1,-1*val);
		}
		superFastRead(&q);
		for(int i=0;i<q;i++)
		{
			superFastRead(&id);
			id++;
			printf("%lld\n",query(id));
		}
	}
	return 0;
}