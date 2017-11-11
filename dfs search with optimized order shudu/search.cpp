//search algorithm with shudu game, using dfs with optimized searching direction. ACM book page 350
/*			//input example
000000520
080400000
030009000
501000600
200700000
000300000
600010000
000000704
000000030
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
bool feasible(int a[][9], int x, int y, int n)
{
	if(a[x][y]!=0)
		return false;
	for(int i=0; i<9; ++i)
	{
		if(a[x][i]==n ||a[i][y]==n ||a[(x/3)*3+i/3][(y/3)*3+i%3]==n)
			return false;
	}
	return true;
}



int minind(int b[][9])
{
	int min=999999;
	int x=0,y=0;
	for(int i=0; i<9; ++i)
		for(int j=0; j<9; ++j)
		{
			if(b[i][j]>0 && b[i][j]<min)
			{
				min=b[i][j];
				x=i;
				y=j;
			}
		}
	return x*9+y;
}


void update(int b[][9], int a[][9])
{
	int counter=0;
	for(int i=0; i<9; ++i)
	{
		for(int j=0; j<9; ++j)
		{
			counter=0;
			for(int k=1; k<=9; ++k)
			{
				if(feasible(a, i, j, k))
					++counter;
			}
			b[i][j]=counter;
		}
	}
}


void dfs(int a[][9], int step, int b[][9])
{
	
	if(step==81)
	{
		for(int i=0; i<9; ++i)
		{

			for(int j=0; j<9; ++j)
			{
				cout<<a[i][j];
			}
			cout<<'\n';
		}
		exit(0);
	}
	int stept=step;

	step=minind(b);
	if(a[step/9][step%9]!=0)
		dfs(a, stept+1, b);
	else
	{
		for(int i=1; i<=9; ++i)
		{
			if(feasible(a, step/9, step%9, i))
			{
				a[step/9][step%9]=i;
				update(b, a);
				dfs(a, stept+1, b);
				a[step/9][step%9]=0;
				update(b, a);
			}
		}
		
	}

}





int main()
{
	string line;
	int matrix[9][9];
	int freedom[9][9];
	int s=0;
	
	for(int i=0; i<9; ++i)
	{
		cin>>line;
		for(int j=0; j<9; ++j)
		{
			matrix[i][j]=line[j]-'0';
		}
	}

	update(freedom, matrix);
	
/*

	for(int i=0; i<9; ++i)
	{

		for(int j=0; j<9; ++j)
		{
			cout<<freedom[i][j];
		}
		cout<<'\n';
	}
*/
	
	dfs(matrix,s,freedom);
}
