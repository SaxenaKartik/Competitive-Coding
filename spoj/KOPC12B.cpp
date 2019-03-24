#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

//long long int row[10000001];

/*long long int nCr(long long int n,long long int r)
{
	long long int i,j;

	row[0]=1;

	for(i=1;i<=n;i++)
	{
		for(j=i;j>0;j--)
		{
			row[j]+=row[j-1];
		}
	}

	return row[r];	
}*/


long long int nCrModpDP(int n, int r, int p)
{
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    long long int C[r+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; // Top row of Pascal Triangle
 
    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++)
    {
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)
 
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

int nCrModpLucas(int n, int r, int p)
{
   // Base case
   if (r==0)
      return 1;
 
   // Compute last digits of n and r in base p
   int ni = n%p, ri = r%p;
 
   // Compute result for last digits computed above, and
   // for remaining digits.  Multiply the two results and
   // compute the result of multiplication in modulo p.
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits
}

int main()
{
	int t;
	cin>>t;
	while(t--)	
	{
		long long int n=0,res=0;
		cin>>n;
		//memset(row,0,sizeof(row));
		res=nCrModpLucas(2*n-1,n-1,MOD);
		res*=n;

		cout<<res<<endl;

	}
}