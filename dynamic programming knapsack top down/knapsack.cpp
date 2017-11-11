// This is the knapsack problem for dynamic programming

/*
7            //number of items 
20           //total weight
2 3          //weight& price
4 6
5 7
9 13
3 5
6 9
8 11
*/

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

struct item{
	int weight;
	int value;
};

const int neginf=numeric_limits<int>::min();

int knap(const vector<item>& valuetable, int m, vector<bool>& a, int n, map<vector<bool>, int>& mem); //version 1, the ith put include which item
int knap2(const vector<item>& valuetable, int m, int n, vector<vector<int> >& mem);                  //version 2, whether the ith item included in the package
vector<int> traceback(const vector<item>& valuetable, vector<vector<int> >& mem);


int main()
{
	int n, m;
	cin>>n>>m;
	vector<item> valuetable;
	for(int i=0; i<n; ++i)
	{
		item temp;
		cin>>temp.weight>>temp.value;
		valuetable.push_back(temp);	
	}
	//test input
	/*
	cout<<n<<" "<<m<<'\n';
	for(int i=0; i<valuetable.size(); ++i)
		cout<<valuetable[i].weight<<' '<<valuetable[i].value<<'\n';*/
	vector<bool> a(n);
	map<vector<bool>, int> mem;
	vector<vector<int> > mem2(m+1);

	vector<int> temp(n+1);
	for(int j=0; j<=n; ++j)
		temp[j]=0;

	for(int i=0; i<=m; ++i)
		mem2[i]=temp;

	//cout<<mem2[m-1][n-1];
	for(int i=0; i<n; ++i)
		a[i]=0;
	cout<<knap(valuetable, m, a, n, mem)<<'\n';
	cout<<knap2(valuetable, m, n, mem2)<<'\n';
	vector<int> result=traceback(valuetable, mem2);

	for(int j=0; j<n+1; ++j)
	{
		
		for(int i=0; i<m+1; ++i)
			cout<<mem2[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';


	for(int i=result.size()-1; i>=0; --i)
		cout<<result[i]<<' ';
	cout<<'\n';
}

int knap(const vector<item>& valuetable, int m, vector<bool>& a, int n, map<vector<bool>, int>& mem)
{
	if(m<=0)
		return 0;

	if(mem.count(a)!=0)
		return mem[a];
	else
	{
		int max=neginf;
		for(int i=0; i<n; ++i)
		{
			if(a[i]==0 && (m-valuetable[i].weight>=0))
			{
				a[i]=1;
				int k=knap(valuetable, m-valuetable[i].weight, a, n, mem)+valuetable[i].value;
				if(max<k)
					max=k;
				a[i]=0;
			}
		}
		if(max>=0){
			mem[a]=max;
			return max;
		}
		mem[a]=0;
		return 0;
	}
}


int knap2(const vector<item>& valuetable, int m, int n, vector<vector<int> >& mem)
{
	if(m<0||n<0)
		return neginf;
	if(m==0||n==0)
		return 0;
	if(mem[m][n]>0)
		return mem[m][n];
	int k=knap2(valuetable, m-valuetable[n-1].weight, n-1, mem)+valuetable[n-1].value;
	int k2=knap2(valuetable, m, n-1, mem);
	if(k<k2)
		mem[m][n]=k2;
	else
		mem[m][n]=k;
	return mem[m][n];
}

vector<int> traceback(const vector<item>& valuetable, vector<vector<int> >& mem)
{
	vector<int> temp;
	int m=mem.size()-1;
	int n=mem[0].size()-1;
	cout<<"mn= "<<m<<' '<<n<<mem[m][n]<<'\n';
	while(mem[m][n]>0 )
	{
		if(mem[m][n]==mem[m][n-1])
			n--;
		else
		{
			temp.push_back(n);
			n--;
			m-=valuetable[n].weight;
		}
	}
	return temp;
}

