//practice of breadth-first search page 97
//also contain the function testing shortest path
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct point
{
  int order;
  int parent;
};

void bfs(vector<point>& result, vector<point>& visited, const vector<vector<int> >& adj_matrix, int vertex, bool& loop); //generate bfs tree

void bfsforest(vector<vector<point> >& result, const vector<vector<int> >& adj_matrix, vector<bool>& loops);  //generate bfs forest, test whether loop exist

bool shortest(vector<int>& path, const vector<vector<int> >& adj_matrix, int start, int end);         //find shortest pass

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
  vector<point> visited(size);
  point tempstruct;
  tempstruct.order=0;
  vector<vector<int> > adj_matrix(size);
  vector<int> templist(size);
  fill(templist.begin(), templist.end(), 0);
  fill(visited.begin(), visited.end(), tempstruct);
  fill(adj_matrix.begin(), adj_matrix.end(), templist);
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
  vector<point> result;
  bool loop=false;
  bfs(result, visited, adj_matrix, 0, loop);
  cout<<"Loop?: "<<loop<<'\n';
  for(int i=0; i<result.size(); ++i)
    cout<<itoc[result[i].order]<<' ';
  cout<<'\n';


  //bfs forest
  vector<vector<point> > forest;
  vector<bool> loops;
  bfsforest(forest, adj_matrix, loops);
  for(int i=0; i<forest.size(); ++i)
  {
    for(int j=0; j<forest[i].size(); ++j)
      cout<<itoc[forest[i][j].order]<<' ';
    cout<<"  Loop: "<<loops[i]<<'\n';              //if loop exist
  }
  //find shortest path
  vector<int> path;
  if(shortest(path, adj_matrix, ctoi['f'], ctoi['i']))
  {
    for(int i=0; i<path.size(); ++i)
      cout<<itoc[path[i]]<<' ';
    cout<<'\n';
  }
  else
    cout<<"No path\n";
}


void bfs(vector<point>& result, vector<point>& visited, const vector<vector<int> >& adj_matrix, int vertex, bool& loop)
{
  int counter=1;
  queue<int> visitlist;
  visitlist.push(vertex);
  visited[vertex].order=counter;
  visited[vertex].parent=-1;
  do
  {
    int temp=visitlist.front();
    for(int i=0; i<visited.size(); ++i)
    {
      if(adj_matrix[temp][i])
      {
        if(visited[i].order!=0)
        {
          if(visited[temp].parent!=i)
            loop=true;
        }
        else
        {
          visitlist.push(i);
          counter++;
          visited[i].order=counter;
          visited[i].parent=temp;
        }
      }
    }
    point temppoint;
    temppoint.order=temp;
    temppoint.parent=visited[temp].parent;
    result.push_back(temppoint);
    visitlist.pop();
  }while(!visitlist.empty());
}

void bfsforest(vector<vector<point> >& result, const vector<vector<int> >& adj_matrix, vector<bool>& loops)
{
  vector<point> visited(adj_matrix.size());
  point tempstruct;
  tempstruct.order=0;
  fill(visited.begin(), visited.end(), tempstruct);

  for(int i=0; i<adj_matrix.size(); ++i)
  {
    if(visited[i].order==0)
    {
      vector<point> tree;
      bool loop=false;
      bfs(tree, visited, adj_matrix, i, loop);
      result.push_back(tree);
      loops.push_back(loop);
    }
  }
}

bool shortest(vector<int>& path, const vector<vector<int> >& adj_matrix, int start, int end)
{
  vector<point> visited(adj_matrix.size());
  point tempstruct;
  tempstruct.order=0;
  fill(visited.begin(), visited.end(), tempstruct);
  bool result=false;
  int counter=1;
  queue<int> visitlist;
  visitlist.push(start);
  visited[start].order=counter;
  visited[start].parent=-1;
  do
  {
    int i;
    int temp=visitlist.front();
    for(i=0; i<visited.size(); ++i)
    {
      if(adj_matrix[temp][i])
      {
        if(visited[i].order==0)
        {
          visitlist.push(i);
          counter++;
          visited[i].order=counter;
          visited[i].parent=temp;
          if(i==end)
          {
            result=true;
            break;
          }
        }
      }

    }
    if(result)
      break;   
    visitlist.pop();
  }while(!visitlist.empty());
  if(visited[end].order==0)
    return false;
  int child=end;
  do
  {
    path.push_back(child);
    child=visited[child].parent;
  }while(child!=start);
  path.push_back(child);
  reverse(path.begin(), path.end());
  return true;
}



