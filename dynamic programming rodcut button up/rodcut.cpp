// This is the rodcut problem for dynamic programming

/*
10         //length of rod
1	   //from 1-10, the value of piece
4
4
7
8
11
18
15
17
20
*/

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string.h>


using namespace std;
const int neginf=numeric_limits<int>::min();

int rodcut(int p[], int s[], int n, int trace[]);



int main()
{
	int n;
	cin>>n;
	int p[n], s[n+1];
	for(int i=0; i<n; ++i)
		cin>>p[i];
	int trace[n+1];
	memset(trace, 0, sizeof(trace));
	cout<<rodcut(p, s, n, trace)<<'\n';
	vector<int> result;
	int i=n, k;
	while(i>0)
	{
		k=trace[i];
		result.push_back(k);
		i=i-k;

	}

	for(int i=0; i<result.size(); ++i)
		cout<<result[i]<<' ';
	cout<<'\n';
}

int rodcut(int p[], int s[], int n, int trace[])
{
	s[0]=0;
	trace[1]=1;
	s[1]=p[0];
	for(int i=2; i<=n; ++i)
	{
		int m=neginf;
		int piece=0;
		for(int j=0; j<i; j++)
			if(s[j]+p[i-j-1]>m)
			{
				m=s[j]+p[i-j-1];
				piece=i-j;
			}
		s[i]=m;
		trace[i]=piece;
	}
	return s[n];
}
