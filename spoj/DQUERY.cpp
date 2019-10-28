// Mo's algorithm : relative property of elements with respect to each other in the query
#include <bits/stdc++.h>
using namespace std;
#define SIZE 30005
#define ll long long 

int  a[SIZE];

int n,d,sq;

struct query{
	int l;
	int r;
	int id;
};

query q[200005];

int counter[2000005];
int ans[2000005];
int x=0;

bool cmp(const query a,const query b)
{
	if(a.l/sq != b.l/sq)
		return a.l/sq<b.l/sq;
	else
		return a.r<	b.r;
}

void fastread( int *a){
    char c=0;
    while(c<33){
        c=getchar_unlocked();
    }
    *a=0;
    while(c>33){
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

/*void add(int position) {
	counter[a[position]]++;
	if(counter[a[position]] == 1) {
		x++;
	}
}

void remove(int position) {
	counter[a[position]]--;
	if(counter[a[position]] == 0) {
		x--;
	}
}*/

int main()
{
	fastread(&n);
	sq=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		fastread(a+i);
	}

	fastread(&d);
	for(int i=1;i<=d;i++)
	{
		fastread(&(q[i].l));
		fastread(&(q[i].r));
		q[i].id=i;
	}

	sort(q+1,q+d+1,cmp);

	int start=q[1].l;
	int end=start;	
	counter[a[start]]++;
	int x=1;


	/*int start=0;
	int end = 0;*/
	for(int i=1;i<=d;i++)
	{
		/*int l = q[i].l, r = q[i].r;
		while(start < l) {
			remove(start);
			start++;
		}
		while(start > l) {
			add(start-1);
			start--;
		}
		while(end <= r) {
			add(end);
			end++;
		}
		while(end > r+1) {
			remove(end-1);
			end--;
		}*/

		while(start<q[i].l)
		{
			counter[a[start]]--;
			if(counter[a[start]]==0)
				x--;
			start++;
		}
		while(start>q[i].l)
		{
			start--;
			counter[a[start]]++;
			if(counter[a[start]]==1)
				x++;
		}
		while(end<q[i].r)
		{
			end++;
			counter[a[end]]++;
			if(counter[a[end]]==1)
				x++;
		}
		while(end>q[i].r)
		{
			counter[a[end]]--;
			if(counter[a[end]]==0)
				x--;
			end--;	
		}


		ans[q[i].id]=x;
	}

	for(int i=1;i<=d;i++)
	{
		printf("%d\n", ans[i]);
	}
}