//this is the implementation of topological sort given a directed acyclic graph
/*
9	number of nodes
12	number of edges
0 2	edges start and end
4 5
2 5
2 3
5 3
5 6
3 6
3 1
3 7
6 8
1 7
7 8
*/

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;


void dfs(int adj[], int n, int visited[], int index, int& timer)
{
  for(int i=0; i<n; ++i)
  {
    if(adj[index*n+i]==1 && visited[i]==0)
    {
      ++timer;
      dfs(adj, n, visited, i, timer);
      ++timer;
    }
  }
  visited[index]=timer;
}

int main()
{
	int n, ne;
	cin>>n>>ne;
	int adj[n*n]={0};
	int a,b;
	int visited[n]={0};
	int timer=0;

	for(int i=0; i<ne; ++i)
	{
		cin>>a>>b;
		adj[a*n+b]=1;
	}
	/*
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
			cout<<adj[i*n+j]<<' ';
		cout<<'\n';
		
	}

	*/
	for(int i=0; i<n; ++i)
	{
	  if(visited[i]==0)
	  {
	    dfs(adj, n, visited, i, timer);
	    timer++;
	  }
	}
	/*
	for(int i=0; i<n; ++i)
	  cout<<visited[i]<<' ';
	cout<<'\n';
	*/
	vector<int> map(n);
	 for(int i=0;i<n;i++)
	   map[i]=i;
	 sort( map.begin(),map.end(), [&](int x,int y){return visited[x]>visited[y];} );
	 
	for(int i=0; i<n; ++i)
	  cout<<map[i]<<' ';
	cout<<'\n';
}
