//bisection algorithm for cable cut ACM book page 141
/*input:
4  //numble of cables
11  //number of segments required
8.02 7.43 4.57 5.39  // the length of each cables
*/


#include <iostream>
#include <iomanip>

using namespace std;

bool condition(double d, double l[], int n, int k)
{
	int sum=0;
	for(int i=0; i<n; ++i)
	{
		sum+=(int)(l[i]/d);
	}
	if(sum<k) return false;
	return true;
}

int main()
{
	int n,k;
	cin>>n>>k;
	double l[n];
	for(int i=0; i<n; ++i)
	{
		cin>>l[i];
	}
	double ub=100000, lb=0;
	double mid;

	for(int i=0; i<100; ++i)
	{
		mid=0.5*(ub+lb);
		if(ub-lb<0.005)
			break;
		if(condition(mid, l, n, k))
			lb=mid;
		else
			ub=mid;		
	}
	cout<<fixed;
	cout<<setprecision(2)<<lb<<'\n';
}
