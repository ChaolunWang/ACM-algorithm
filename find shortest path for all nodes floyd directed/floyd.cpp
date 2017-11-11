//implementation of floyd algorithm for finding the transitive closure, page 239


//input example
/*
4 //number of vertexes
1 2 3 4 //vertexes
5 //number of edges
1 3 3 //edges start, end and weight
2 1 2
3 2 7
3 4 1
4 1 6
*/
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;
const int inf=9999999;


int main()
{
	int sizev, sizee;
	cin>>sizev;
	int vertex[sizev];
	for(int i=0; i<sizev; ++i)
	{
		cin>>vertex[i];
	}
	cin>>sizee;
	
	int adj_matrix[sizev][sizev], temp_matrix[sizev][sizev];
	
	for(int i=0; i<sizev; ++i)
		for(int j=0; j<sizev; ++j)
		{
			if(i==j)
				adj_matrix[i][j]=0;
			else
				adj_matrix[i][j]=inf;
		}
	for(int i=0; i<sizee; ++i)
	{
		int a, b, c;
		cin>>a>>b>>c;
		adj_matrix[a-1][b-1]=c;
	}

	/*
	//test input
	for(int i=0; i<sizev; ++i)
	{
		for(int j=0; j<sizev; ++j)
			cout<<adj_matrix[i][j]<<' ';
		cout<<'\n';
	}*/		

	//algorithm
	for(int k=0; k<sizev; ++k)
	{
		for(int i=0; i<sizev; ++i)
			for(int j=0; j<sizev; ++j)
				temp_matrix[i][j]=min(adj_matrix[i][j],(adj_matrix[i][k]+adj_matrix[k][j]));
		memcpy(adj_matrix, temp_matrix, sizev*sizev*sizeof(int));
	}
	
	//output
	for(int i=0; i<sizev; ++i)
	{
		for(int j=0; j<sizev; ++j)
			cout<<adj_matrix[i][j]<<' ';
		cout<<'\n';
	}
}







