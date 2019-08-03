#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
long long int modularExponentiation(long long int x,long long int n,long long int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M)%M;
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int M=1000000007;
    long long int t,n,sum=0;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        /*for(int i=2;i<=n;i++)
        {
            sum=sum+modularExponentiation(2,i-1,M);
            cout<<"sum = "<<sum<<endl;
        }*/
        sum = modularExponentiation(2,n,M);
        sum-=2;
        sum=sum+n;
        sum=sum%M;
        cout<<sum;
        cout<<endl;
    }
    return 0;
}