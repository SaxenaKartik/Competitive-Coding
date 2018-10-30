#include <bits/stdc++.h>
using namespace std;

/*struct elements 
{
	int score[35];
	int number[35];
	int count;
	int index;
};

elements a[100005];*/

vector<pair<int, int> >problem;
vector<pair<int, int> >cnt;

/*bool cmp(int a, int b)
{
	return a<b;
}
*/
int main()
{
	int p,s;
	scanf("%d %d", &p, &s);
	int score[s+1], number[s+1],count=0;

	for(int i=1;i<=p;i++)
	{
		count=0;
		// cnt[i].first=i;
		for(int j=1;j<=s;j++)
		{	
			scanf("%d", &score[j]);
		}
		for(int j=1;j<=s;j++)
		{
			scanf("%d",&number[j]);

			problem.push_back(make_pair(score[j],number[j]));
		}
		sort(problem.begin(), problem.end());

		for(int j=0;j<s-1;j++)
		{
			if(problem[j].second>problem[j+1].second)
				count++;
		}
		problem.clear();
		cnt.push_back(make_pair(count, i));
	}
	sort(cnt.begin(), cnt.end());

	// for(int i=1;i<=p;i++)

	/*for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=s;j++)
		{
			printf("%d ", a[i].score[j]);
		}
		printf("\n");
	}*/

	/*int temp;

	for(int i=1;i<=p;i++)
	{
		// printf("here\n");
		for(int j=1;j<=s-1;j++)
		{
			if(problem[i].second>problem[i].second)
			{
				// printf("here\n");
				a[i].count++;
			}
		}
	}*/

	/*for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=s;j++)
		{
			printf("%d ", a[i].number[j]);
		}
		printf("\n");
	}*/

	// sort(a+1, a+p+1, cmp1);

	vector<pair<int, int> >::iterator it=cnt.begin();
	for( ;it!=cnt.end();it++)
	{
		printf("%d\n", (*it).second);
	}

	return 0;
}