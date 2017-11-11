//implementation of prim algorithm for building the minimal spanning tree problem page 245


//input example
/*
6  //number of vertex
0 1 2 3 4 5 //vertex id
10 //number of weighted edge
0 1 3 //edge: two ends and weight
0 5 5
0 4 6
1 2 1
1 5 4
2 3 6
2 5 4
3 4 8
3 5 5
4 5 2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
const int inf=numeric_limits<int>::max();

struct edge
{
	int start;
	int end;
	int weight;
};



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
	vector<edge> edges;
	for(int i=0; i<sizee; ++i)
	{
		edge tempedge;
		cin>>tempedge.start>>tempedge.end>>tempedge.weight;
		edges.push_back(tempedge);
	}
	

	vector<int> edgeid;
	bool vertexid[sizev];
	for(int i=0; i<sizev; ++i)
		vertexid[i]=false;
	vertexid[0]=true;
	for(int k=1; k<sizev; ++k)
	{
		int min=inf;
		int minid=0;
		for(int i=0; i<sizee; ++i)
		{
			if((!vertexid[edges[i].start] && vertexid[edges[i].end])||(vertexid[edges[i].start] && !vertexid[edges[i].end]))
			{
				if(edges[i].weight<min)
				{
					min=edges[i].weight;
					minid=i;
				}
			}

		}		
		vertexid[edges[minid].start]=vertexid[edges[minid].end]=true;
		edgeid.push_back(minid);
	}			
	//output
	for(int i=0; i<edgeid.size(); ++i)
		cout<<edges[edgeid[i]].start<<' '<<edges[edgeid[i]].end<<'\n';
}







