#include <bits/stdc++.h>
using namespace std;
int ans[3005];
list<int> v;


void pre()
{
	for(int i=2;i<=34000;i++)
	{
		v.push_back(i);
	}

	int count=0;
	list<int>::iterator it,it2;
	while(count<=3000)
	{
		int k=v.front();
		
		ans[count]=k;
		count++;
		//cout<<count<<" "<<k<<endl;
		int s=0;
		for(it=v.begin();it!=v.end();it=it2,s++)
		{
			it2=it;
			++it2;
			if(s%k==0)
				v.erase(it);
			// cout<<*it;
			// break;
		}
		// break;
	}
}

int main()
{
	pre();
	int n;
	while(true)
	{
		scanf("%d",&n);
		if(n==0) break;
		printf("%d\n", ans[n-1]);
	}

}