#include <iostream> 
int main() 
{	int t,sum=0,n; 
	std::cin>>t; 
	while(t--)
	{
		std::cin>>n;
		if(n>0)
			sum+=n;
	}
	std::cout<<sum;
}