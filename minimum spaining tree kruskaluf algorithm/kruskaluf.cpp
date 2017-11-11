//implementation of kruskaluf algorithm for building the minimal spanning tree problem page 252
//together with union find datastructure

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

using namespace std;

class UF { 
	int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
	UF(int N) 
	{
		cnt = N;
		id = new int[N];
		sz = new int[N];
		for(int i=0; i<N; i++) 
		{
			id[i] = i;
			sz[i] = 1;
		}
	}

	~UF() {
		delete [] id;
		delete [] sz;
	}

	// Return the id of component corresponding to object p.
	int find(int p) 
	{
		int root = p;
		while (root != id[root])
			root = id[root];
		while (p != root) //path compression
		{
			int newp = id[p];
			id[p] = root;
			p = newp;
		}
		return root;
	}

	// Replace sets containing x and y with their union.
	void merge(int x, int y) 
	{
		int i = find(x);
		int j = find(y);
		if (i == j) return;
		// make smaller root point to larger one
		if (sz[i] < sz[j]) 
		{
			id[i] = j;
			sz[j] += sz[i];
		} 
		else	
		{
			id[j] = i;
			sz[i] += sz[j];
		}
		cnt--;
	}

	// Are objects x and y in the same set?
	bool connected(int x, int y) 
	{
		return find(x) == find(y);
	}

	// Return the number of disjoint sets.
	int count() 
	{
		return cnt;
	}
};

struct edge
{
	int start;
	int end;
	int weight;
};

struct compare
{
	bool operator() (const edge& i, const edge& j)
	{
		return i.weight<j.weight;
	}
} compedge;

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
	//algorithm
	sort(edges.begin(), edges.end(), compedge);

	//test sorted edge
	for(int i=0; i<sizee; ++i)
		cout<<edges[i].start<<' '<<edges[i].end<<' '<<edges[i].weight<<'\n'; //pass

	vector<int> edgeid;
	UF vertexid(sizev);
	int e=0, k=-1;

	while(e<sizev-1)
	{
		++k;
		if(!vertexid.connected(edges[k].start,edges[k].end))
		{
			vertexid.merge(edges[k].start,edges[k].end);
			edgeid.push_back(k);
			++e;
		}
	}

	//output
	for(int i=0; i<edgeid.size(); ++i)
		cout<<edges[edgeid[i]].start<<' '<<edges[edgeid[i]].end<<'\n';
}







