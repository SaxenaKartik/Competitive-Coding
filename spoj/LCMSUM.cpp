#include <bits/stdc++.h>
using namespace std;

long long int s[1000001]={0};
void fastscan(long long int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void spf(long long int n)
{
	// long long int s[n+1];

	s[1]=1;
	for(long long int i=2;i<=n;i++)
	{
		if(s[i]==0)
		{
			s[i]=i;
			for(long long int j=2*i;j<=n;j+=i)
			{
				if(s[j]==0)
				{
					s[j]=i;
				}
			}
		}
	}
	// return s;
}

map <long long int, long long int> primefactorisation(long long int n)
{
	map<long long int,long long int> map;

	int curr=s[n];
	int count=1;

	map.insert(make_pair(1,1));
	while(n>1)
	{
		n=n/s[n];
		if(curr==s[n])
		{
			count++;
			continue;
		}	
		map.insert(make_pair(curr,count));
		curr=s[n];
		count=1;
	}
	return map;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int t;
	fastscan(t);
	while(t--)
	{

		long long int n;
		fastscan(n);
		// long long int* s;
		spf(n);

		map <long long int,long long int> m;
		m=primefactorisation(n);
		
		map<long long int,long long int>m1;
		map<long long int,long long int>::iterator it;
		
		long long int sum=0;
		/*for(it=m.begin();it!=m.end();++it)
		{
			cout<<it->first<<" "<<it->second<<"\n";
		}*/
		// cout<<"size of map : "<<m.size()<<"\n";
		int size=m.size();

		for(int i=2	;i<n;i++)
		{
			// cout<<s[i]<<"\n";
			// cout<<it->first<<" "<<it->second<<"\n";
			m1=primefactorisation(i);
			for(it=m1.begin();it!=m1.end();++it)
			{
				// cout<<i<<" : "<<it->first<<" "<<it->second<<"\n";
				if(!m[it->first])
				{
					sum+=n*(pow(it->first,it->second));
					// cout<<"sum : "<<sum<<"\n";
				}
				else
				{
					long long int k,s;
					k=m1[it->first];
					s=m[it->first];
					if((k-s)>0)
					{
						sum+=n*pow(it->first,(k-s));
						// cout<<"sum : "<<sum<<"\n";
					}
				}
			}

		}
		// cout<<sum<<"\n";
		// cout<<"size of map : "<<size<<"\n";
		sum+=n*size;	
		cout<<sum<<"\n";
	}
}