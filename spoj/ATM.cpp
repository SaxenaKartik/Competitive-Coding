#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	double y;
	scanf("%d %lf", &x, &y);

	if(x%5==0 && (x+0.5)<=y){

		printf("%.2lf\n", y-(x+0.5));
	}
	else
	{
		printf("%.2lf\n", y);
	}
	return 0;
}