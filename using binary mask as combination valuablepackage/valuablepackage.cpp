//most valuable package problem page 91

//bit operation

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct bitoperand
{
  int data;
  int size;
  int bound;
  int mask;

  bitoperand(int datasize)
  {
    data=0;
    size=datasize;
    bound=pow(2, datasize);
    mask=1;
  }

  bool operator++()
  {
    if(data<bound-1)
    {
      ++data;
      mask=1;
      return true;
    }
    else
      return false;
  }
  
  int nextbit()
  {
    int result;
    if(mask==bound)
      return -1;
    else if((mask&data) == mask)
      result=1;
    else
      result=0;
    mask=mask<<1;
      return result;
  }
};

struct package {
  int weight;
  int price;
};

int main()
{
  /*
  //testing bitoperand
  bitoperand test(5);
  ++test;
  cout<<test.mask<<'\n';
  cout<<test.data<<'\n';
  cout<<test.nextbit()<<test.nextbit()<<test.nextbit()<<'\n';
  ++test;
  cout<<test.mask<<'\n';
  cout<<test.data<<'\n';
  cout<<test.nextbit()<<test.nextbit()<<test.nextbit()<<'\n';
  ++test;
  cout<<test.mask<<'\n';
  cout<<test.data<<'\n';
  cout<<test.nextbit()<<test.nextbit()<<test.nextbit()<<'\n';
  ++test;
  cout<<test.mask<<'\n';
  cout<<test.data<<'\n';
  cout<<test.nextbit()<<test.nextbit()<<test.nextbit()<<'\n';*/
  int size;
  int bagsize=10;
  int max=0;
  vector<int> result;
  
  cin>>size;
  cin>>bagsize;
  package data[size];
  for(int i=0; i<size; ++i)
    cin>>data[i].weight>>data[i].price;
  
  bitoperand combination(size);
  
  while(++combination)
  {
    int totalsize=0;
    int totalprice=0;
    vector<int> tempresult;
    for(int i=0; i<size; ++i)
    {
      int temp=combination.nextbit();
      if(temp==1)
        tempresult.push_back(i+1);
      totalsize+=temp*data[i].weight;
      totalprice+=temp*data[i].price;
    }
   // cout<<totalsize<<' '<<totalprice<<'\n';
    if(totalsize<=bagsize && totalprice>max)
    {
      max=totalprice;
      result=tempresult;
    }
  }
  for(int i=0; i<result.size(); ++i)
    cout<<result[i]<<' ';
  cout<<'\n';
}





