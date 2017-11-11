//stable marrage problem,object is to find the best match to satisfy a certain preference as much as possible. page 293

/*input example
3 //number of maches

2 3 1 2 3 3 //matrix of favorate points. 9 data sets, 2 3 1 means:men N0 1 have women N0 2 to be 1st favoite, men N0 1 have women N0 3 to be 2nd favoite. women N0 1 have men N0 1 to be 3nd favoite
3 1 1 3 2 1 //then the next 3 digits means the same thing for women NO1, the last two rows indicates the preference of men No2 women No2, men No3 women No3 separately.
3 2 2 1 1 2

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int mtow;
    int wtom;
    int mark;
};

int main()
{
    int size;
    cin>>size;
    node data[size][size];
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
        {
           cin>>data[i][j].mtow;
           cin>>data[i][j].wtom;
           data[i][j].mark=0;
        }
    /*//test favorate matrix
    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<size; ++j)
        {
           cout<<data[i][j].mtow<<' ';
           cout<<data[i][j].wtom<<"  ";
        }    
        cout<<'\n';
    }*/
    
    //algorithm
    queue<int> index_queue;
    for(int i=0; i<size; ++i)
        index_queue.push(i);
    while(!index_queue.empty())
    {
        int w=index_queue.front();
        //cout<<w<<'\n';
        index_queue.pop();
        for(int i=1; i<=size; ++i)
        {
           bool succeed=false;
           for(int j=0; j<size; ++j)
               if(data[w][j].mtow==i)
               {
                  bool found=false;
                  for(int k=0; k<size; ++k)
                  {
                      if(data[k][j].mark==1)
                      {
                          if(data[k][j].wtom>data[w][j].wtom)
                          {
                              data[k][j].mark=0;
                              // cout<<"lost: "<<k+1<<' '<<j+1<<'\n';
                              data[w][j].mark=1;
                             //  cout<<w+1<<' '<<j+1<<'\n';
                              succeed=true;
                              index_queue.push(k);
                          }
                          found=true;
                          break;
                      }
                  }
                  if(!found)
                  {
                      data[w][j].mark=1;
                      // cout<<w+1<<' '<<j+1<<'\n';
                      succeed=true;
                  }
               }
            if(succeed)
                break;
        }
    }


    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
           if(data[i][j].mark)
               cout<<i+1<<' '<<j+1<<'\n';  
}





