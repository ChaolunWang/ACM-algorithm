//This is the code to find the maximize of fully connected component in undirected graph with searching and highly efficient pruling

/*
5
a
b
c
d
e
8
a c
a d
a b
a e
b d
c d
c e
d e
*/



#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool condition(const vector<vector<int> >& adj_matrix, const vector<int>& result, int index)
{

	for(int i=0; i<result.size(); i++)
	{
		if(adj_matrix[result[i]][index]==0)
			return false;
	}
	return true;
}


int mfc(const vector<vector<int> >& adj_matrix, vector<int>& result, int index, int ub, int& max, vector<int>& record)
{
	int a=0, b=0;
	vector<int> recorda, recordb;
	if(index==adj_matrix.size()-1 || ub<=max)
		return 0;

	if(condition(adj_matrix, result, index+1))
	{
		result.push_back(index+1);
		a=mfc(adj_matrix, result, index+1, ub, max, recorda)+1;
		result.pop_back();
	}
	b=mfc(adj_matrix, result, index+1, ub-1, max, recordb);
	int m;
	if(a>b)
	{
		m=a;
		record=recorda;
		record.push_back(index+1);
	}		
	else
	{
		m=b;
		record=recordb;
	}
	if(m>max)
		max=m;
	return m;
}

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
  } 
	
  */
	int max=0;
	vector<int> sol, record;
	int result=mfc(adj_matrix, sol, -1, size, max, record);
	cout<<result<<'\n';

	for(int i=0; i<record.size(); ++i)
		cout<<itoc[record[i]]<<' ';
	cout<<'\n';

}
