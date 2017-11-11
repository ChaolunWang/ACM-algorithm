//assign different jobs for different individuals

/*
// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {1,2,3};

  std::sort (myints,myints+3);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } while ( std::next_permutation(myints,myints+3) );

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}

*/
#include <iostream>    
#include <algorithm>    
#include <cmath>
#include <vector>

using namespace std;

bool comparithm(const vector<int>& i, const vector<int>& j)
{
  return i.back()<j.back();
}

int main () 
{
  int size;
  vector<vector<int> > result;
  cin>>size;
  int data[size][size];
  int index[size];
  for(int i=0; i<size; ++i)
    for(int j=0; j<size; ++j)
      cin>>data[i][j];
     
  for(int i=0; i<size; ++i)
    index[i]=i;
  
  do
  {
    vector<int> temp;
    int totaltime=0;
    for(int i=0; i<size; ++i)
      temp.push_back(index[i]+1);
    for(int i=0; i<size; ++i)
      totaltime+=data[i][index[i]];
    temp.push_back(totaltime);
    result.push_back(temp);

  } while (next_permutation(index,index+size));
/*
   for(int i=0; i<result.size(); ++i)
   {
     for(int j=0; j<result[0].size(); ++j)
       cout<<result[i][j]<<' ';
     cout<<'\n';
   }*/
 
  partial_sort (result.begin(), result.begin()+1, result.end(),comparithm);

  for(int j=0; j<result[0].size(); ++j)
    cout<<result[0][j]<<' ';
  cout<<'\n';

  return 0;
}


