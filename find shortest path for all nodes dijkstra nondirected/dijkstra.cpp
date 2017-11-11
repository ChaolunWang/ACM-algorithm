//practice of dijkstra method to find the shortest path to all points page 258


//input
/*
5  //number of vertex
1 2 3 4 5 //vertex
7  //number of edges
1 2 3 //two ends of edge and length
1 4 7
2 4 2
2 3 4
3 4 5
3 5 6
4 5 4

*/

#include<iostream>
#include<vector>

using namespace std;

const int inf=9999999;

struct node
{
	int id;
	int from;
	int distant;
	int deleted;
};

int main()
{
	int sizev, sizee;
	cin>>sizev;
	node vertex[sizev];
	for(int i=0; i<sizev; ++i)
	{
		cin>>vertex[i].id;
		vertex[i].from=0;
		vertex[i].distant=inf;
		vertex[i].deleted=0;
	}

	cin>>sizee;
	int adjmatrix[sizev][sizev];
	for(int i=0; i<sizev; ++i)
	{
		for(int j=0; j<sizev; ++j)
		{
			if(i!=j)
				adjmatrix[i][j]=inf;
			else
				adjmatrix[i][j]=0;
		}
	}
	/*
	//adj matrix
	for(int i=0; i<sizev; ++i)
	{
		for(int j=0; j<sizev; ++j)
		{
			cout<<adjmatrix[i][j]<<' ';
		}
		cout<<'\n';
	}
	*/
	for(int i=0; i<sizee; ++i)
	{
		int a, b, c;
		cin>>a>>b>>c;
		adjmatrix[a-1][b-1]=adjmatrix[b-1][a-1]=c;
	}

	/*
	//adj matrix
	for(int i=0; i<sizev; ++i)
	{
		for(int j=0; j<sizev; ++j)
		{
			cout<<adjmatrix[i][j]<<' ';
		}
		cout<<'\n';
	}
	*/
	//algorithm
	vertex[0].distant=0;
	int visited[sizev];
	for(int k=0; k<sizev; ++k)
	{
		int u=0, mindis=inf;
		for(int i=0; i<sizev; ++i)
		{
			if(vertex[i].deleted==0 && vertex[i].distant<=mindis)
			{
				u=i;
				mindis=vertex[i].distant;
			}
		}
		vertex[u].deleted=1;
		visited[k]=u;
		for(int i=0; i<sizev; ++i)
		{
			if(vertex[i].deleted==0 && adjmatrix[u][i]!=inf &&((vertex[u].distant+adjmatrix[u][i])<vertex[i].distant))
			{
                                //cout<<"node: "<<i+1<<"  dis: "<<vertex[i].distant<<'\n';
				vertex[i].distant=vertex[u].distant+adjmatrix[u][i];
				//cout<<"node after: "<<i+1<<"  dis: "<<vertex[i].distant<<'\n';
				vertex[i].from=vertex[u].id;
			}
		}

	}

	//output
	for(int k=1; k<sizev; ++k)
	{
		int end=visited[k];
		int length=vertex[end].distant;
		cout<<"from 1 to "<<end+1<<" : "<<end+1<<" ";
		while(end!=0)
		{
			int last=vertex[end].from;
			cout<<last<<' ';
			end=last-1;
		}
		cout<<"  total distant is : "<<length<<"\n";
	}
}



