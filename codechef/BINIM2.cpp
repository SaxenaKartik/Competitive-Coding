#include<bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define ll long long

ll n,t;
string s,x;
// vector<string> v;
// multiset<int, greater<int> > one,zero;
int32_t main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;

		int sum00=0, sum01=0, sum10=0,sum11=0,sumdee=0, sumdum=0;
		// int sum1=0;
		while(n--)
		{
			cin>>x;
			// v.push_back(x);
			// reverse(x.begin(), x.end());

			if(x[0]=='1' && x[x.length()-1]=='1')
			{
				sum11++;
				/*int count0=0;
				for(auto ch : x)
				{
					if(ch=='0')
						count0++;
				}
				// debug(count0);
				sum1+=x.length()-x.find_last_of('0')-1;
				zero.insert(count0);*/
			}
			else if(x[0]=='1' && x[x.length()-1]=='0')
			{
				sum10++;
				/*int count1=0;
				for(auto ch : x)
				{
					if(ch=='1')
						count1++;
				}
				// debug(count1);

				sum0+=x.length()-x.find_last_of('1')-1;
				one.insert(count1);*/
			}
			else if(x[0]=='0' && x[x.length()-1]=='1')
			{
				sum01++;
			}
			else
			{
				sum00++;
			}
		}

		sumdee=sum10+sum01+sum00;
		sumdum=sum11+sum01+sum10;
		/*for(auto k1 : zero)
		{
			// debug(k1);
			sum0+=k1;
		}

		for(auto k2 : one)
		{
			// debug(k2);
			sum1+=k2;
		}
*/
		// debug(sum1);
		// debug(sum0);

		if(sumdee>sumdum)
		{
			cout<<"Dum"<<endl;
		}
		else if(sumdum>sumdee)
		{
			cout<<"Dee"<<endl;
		}
		else
		{
			cout<<s<<endl;
		}
	}
}
