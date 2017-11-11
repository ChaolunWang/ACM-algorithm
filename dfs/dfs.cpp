//practice of depth-first search page 95
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& result, vector<int>& visited, const vector<vector<int> >& adj_matrix, int last, int vertex, int count, bool& loop);

void dfsforest(vector<vector<int> >& result, const vector<vector<int> >& adj_matrix, vector<bool>& loops);

int main()
{
  map<char, int> ctoi;
  map<int, char> itoc;
  int size, edges;
  cin>>size;
  for(int i=0; i<size; ++i)
  {
    char temp;
    cin>>temp;
    itoc[i]=temp;
    ctoi[temp]=i;
  }

  cin>>edges;
  
  /*
  //test input of vertex
  cout<<itoc[5]<<'\n';
  cout<<ctoi['f']<<'\n';*/
  vector<int> visited(size);
  vector<vector<int> > adj_matrix(size);
  fill(visited.begin(), visited.end(), 0);
  fill(adj_matrix.begin(), adj_matrix.end(), visited);
  for(int i=0; i<edges; ++i)
  {
    char temp1, temp2;
    cin>>temp1>>temp2;
    adj_matrix[ctoi[temp1]][ctoi[temp2]]=adj_matrix[ctoi[temp2]][ctoi[temp1]]=1;    
  } 
  /*
  //test adjacent matrix
  for(int i=0; i<size; ++i)
  {
    for(int j=0; j<size; ++j)
      cout<<adj_matrix[i][j]<<' ';
    cout<<'\n'; 
  } */
  vector<int> result;
  bool loop=false;
  dfs(result, visited, adj_matrix, 0, 0, 0,loop);
  cout<<"Loop?: "<<loop<<'\n';
  for(int i=0; i<result.size(); ++i)
    cout<<itoc[result[i]]<<' ';
  cout<<'\n';

  //dfs forest
  vector<vector<int> > forest;
  vector<bool> loops;
  dfsforest(forest, adj_matrix, loops);
  for(int i=0; i<forest.size(); ++i)
  {
    for(int j=0; j<forest[i].size(); ++j)
      cout<<itoc[forest[i][j]]<<' ';
    cout<<"  Loop: "<<loops[i]<<'\n';
  }
}


void dfs(vector<int>& result, vector<int>& visited, const vector<vector<int> >& adj_matrix, int last, int vertex, int count, bool& loop)
{
  count++;
  visited[vertex]=count;
  result.push_back(vertex);
  for(int i=0; i<visited.size(); ++i)
  {
    if(adj_matrix[vertex][i]!=0)
    {
      if(visited[i]!=0)
      {
        if(i!=last)
          loop=true;
      }
      else
        dfs(result, visited, adj_matrix, vertex, i, count, loop);
    }
  }
}

void dfsforest(vector<vector<int> >& result, const vector<vector<int> >& adj_matrix, vector<bool>& loops)
{
  vector<int> visited(adj_matrix.size());
  fill(visited.begin(), visited.end(), 0);
  for(int i=0; i<adj_matrix.size(); ++i)
  {
    if(visited[i]==0)
    {
      vector<int> tree;
      bool loop=false;
      dfs(tree, visited, adj_matrix, i, i, 0, loop);
      result.push_back(tree);
      loops.push_back(loop);
    }
  }
}


