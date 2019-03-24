#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long

unordered_map<int ,int> m;
vector <pair<char, int> > v; //storing pair of values of character and x
vector <int> a; //storing the x for every query in sorted manner
vector <int> bit(200001,0);

void update(int x,int val,int n) //sets the BIT[x] to number of numbers less than x
{
	for(;x<=n;x+= x&-x)
	{
		bit[x]+=val;
	}
}


int query(int x) //returns the number of elements smaller than any x
{
	int sum=0;
	for(;x>0;x-= x&-x)
	{
		sum+=bit[x];
	}
	return sum;
}


int search(int val)   //doing a binary search in a for the val-th smallest element 
{  
	int x,y,z,ans=a.size();
	x=0;
	y=a.size()-1;
	while(x<=y){
        
		z=(x+y)/2;
    
		if(query(m[a[z]])>=val){
			ans=z;
			y=z-1;
		}
		else
		{
			x=z+1;
		}
	}
	return ans;
}

int main()
{
	int q;
	int x,j;
	scanf("%d", &q);
	char ch;
	
	v.clear();
	a.clear();
	m.clear();

	for(int i=0;i<q;i++)
	{
		cin>>ch;
		scanf("%d",&x);
		v.push_back(make_pair(ch,x));  //making a vector storing every query pair
		m[x]=1; //marking all the coordinates to 1 initially
	}

	for(auto u:m)
	{
		// cout<<u.first<<endl;
		a.push_back(u.first); //entering only unique values in a
	}

	sort(a.begin(),a.end()); //sorting all the values in queries 

	for(int i=0;i<a.size();i++)
	{
		m[a[i]]=i+1; //coordinate compression and storing in unorderd_map
	}

	/*HOW TO UPDATE THE BIT?

	www.quora.com/Competitive-Programming-In-problem-orderset-SPOJ-how-do-we-find-the-number-of-elements-less-than-a-number-using-bit
	*/

	for(int i=0;i<q;i++) //for attending to queries 
	{
		if(v[i].first=='I')
		{
			if(query(m[v[i].second])==query(m[v[i].second]-1))
			{
				update(m[v[i].second],1,a.size()); //updating the numbers in BIT
			}
		}
		else if(v[i].first=='D')
		{
			if(query(m[v[i].second])!=query(m[v[i].second]-1))
			{
				update(m[v[i].second],-1,a.size());
			}
		}
		else if(v[i].first=='K') //to return the kth smallest element 
		{
			j=search(v[i].second); 
			if(j==a.size())
			{
				printf("invalid\n");
			}
			else
			{
				printf("%d\n", a[j]);
			}
		}	
		else
		{
			j=lower_bound(a.begin(),a.end(),v[i].second)-a.begin(); //finding the index of first value in range a.begin() to a.end() that is bigger than v[i].second 
			j--;
			if(j<0)
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", query(m[a[j]]));
			}
		}
	}
	
	return 0;
}