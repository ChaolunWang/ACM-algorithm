//traveling salesman


#include <iostream>    
#include <algorithm>    
#include <cmath>
#include <vector>

using namespace std;

struct point{
  double x;
  double y;
};

double distances(const point& a, const point& b);

int main () 
{
  int size;
  vector<vector<int> > result;
  vector<double> result_distance;
  cin>>size;
  point data[size];
  int index[size];
  for(int i=0; i<size; ++i)
    cin>>data[i].x>>data[i].y;
     
  for(int i=0; i<size; ++i)
    index[i]=i;
  
  do
  {
    vector<int> temp;
    double totaldis=0;
    for(int i=0; i<size; ++i)
      temp.push_back(index[i]+1);
    for(int i=0; i<size-1; ++i)
    {
      totaldis+=distances(data[index[i]], data[index[i+1]]);
    }
    totaldis+=distances(data[index[size-1]], data[index[0]]);
    result.push_back(temp);
    result_distance.push_back(totaldis);
  } while (next_permutation(index+1,index+size));

  for(int i=0; i<result.size(); ++i)
  {
    for(int j=0; j<size; ++j)
      cout<<result[i][j]<<' ';
    cout<<result_distance[i]<<'\n';
  }

  double min;
  int minindex;

  for(int i=0; i<result.size(); ++i)
  { 
    if(i==0)
    {
      min=result_distance[0];
      minindex=0;
    }
    else if(result_distance[i]<min)
    {
      min=result_distance[i];
      minindex=i;
    }
  }
  cout<<'\n';
  for(int j=0; j<size; ++j)
    cout<<result[minindex][j]<<' ';
  cout<<1<<' '<<min<<'\n';
  return 0;
}

double distances(const point& a, const point& b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
