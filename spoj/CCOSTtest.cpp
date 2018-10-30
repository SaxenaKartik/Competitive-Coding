#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define MAXR 500005
#define MAXV 10000005

int tree[MAXV], ans[4*MAXR], n, r, mr;

struct points
{
    int x, y, val;
};

struct query
{
    int x, y, pos;
};

points p[MAXN];
query q[MAXR];

bool cmpP(const points &a, const points &b)
{
    return a.y<b.y;
}

bool cmpQ(const query &a, const query &b)
{
    return a.y<b.y; 
}

void update(int idx, int val)
{
    if(idx<=0)
        return;
    while(idx<=MAXV)
    {
        tree[idx]+=val;
        idx+=idx&-idx;
    }
}

int read(int idx)
{
    if(idx<=0)
        return 0;
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx&-idx;
    }
    return sum;
}

int main()
{
    int t, x1, y1, x2, y2, curr, pre, qre;
    scanf("%d", &t);
    while(t--)
    {
        memset(tree, 0, sizeof(tree));
        scanf("%d", &n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].val);
            p[i].x++;
            p[i].y++;
        }
        sort(p, p+n, cmpP);
        /*for(int i=0;i<n;i++)
        {
            printf("->%d %d %d\n", p[i].x, p[i].y, p[i].val);
        }*/
        scanf("%d", &r);
        for(int i=0;i<r;i++)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1++;
            y1++;
            x2++;
            y2++;
            curr=4*i;
            q[curr].x=x1-1;
            q[curr].y=y1-1;
            q[curr].pos=curr;
            q[curr+1].x=x1-1;
            q[curr+1].y=y2;
            q[curr+1].pos=curr+1;
            q[curr+2].x=x2;
            q[curr+2].y=y1-1;
            q[curr+2].pos=curr+2;
            q[curr+3].x=x2;
            q[curr+3].y=y2;
            q[curr+3].pos=curr+3;
        }
        mr=4*r;
        sort(q, q+(mr), cmpQ);
        /*for(int i=0;i<mr;i++)
        {
            printf("->%d %d %d\n", q[i].x, q[i].y, q[i].pos);
        }*/
        pre=qre=0;
        while(pre<n && qre<mr)
        {
            //printf("u>> %d %d", p[pre].y, q[qre].y);
            while(pre<n && p[pre].y<=q[qre].y)
            {
                //printf(">0>\n");
                update(p[pre].x, p[pre].val);
                pre++;
            }
            while(qre<mr && q[qre].y==q[qre+1].y)
            {
                //printf(">1>%d %d %d\n", q[qre].y, q[qre+1].y, read(q[qre].x));
                ans[q[qre].pos]=read(q[qre].x);
                qre++;
            }
            //printf(">2> %d\n", read(q[qre].x));
            ans[q[qre].pos]=read(q[qre].x);
            qre++;
        }   
        /*for(int i=0;i<mr;i++)
        {
            printf("->%d ", ans[i]);
        }
        printf("\nTree:\n");
        for(int i=0;i<mr;i++)
        {
            printf("->%d ", tree[i]);
        }
        printf("\n");*/
        for(int i=0;i<r;i++)
        {
            curr=4*i;
            printf("%d\n", ans[curr]+ans[curr+3]-ans[curr+1]-ans[curr+2]);
        }    
    }
    return 0;
}