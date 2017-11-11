//maximum matching problem in bipartite graph page 289

/*input example
5  //number of element in set v
1 2 3 4 5  //set v
5  //number of element in set u
6 7 8 9 10 //set u
10  //number of edge
1 6 //edges
2 6
1 7
3 6
3 8
4 8
4 9
4 10
5 9
5 10

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int value;
    int group;
    int mark;
    int match;
};

int main()
{
    int sizev, sizeu, sizee;
    cin>>sizev;
    cin>>sizeu;
    node data[sizev+sizeu]; 
    for(int i=0; i<sizev; ++i)
    {
        cin>>data[i].value;
        data[i].mark=0;
        data[i].match=0;
        data[i].group=1;
    }
    

    for(int i=sizev; i<sizev+sizeu; ++i)
    {
        cin>>data[i].value;
        data[i].mark=0;
        data[i].match=0;
        data[i].group=2;
    }

    cin>>sizee;
    int edge[sizev+sizeu][sizev+sizeu];
    for(int i=0; i<sizev+sizeu; ++i)
        for(int j=0; j<sizev+sizeu; ++j) 
            edge[i][j]=0;

    for(int i=0; i<sizee; ++i)
    {
       int a, b;
       cin>>a>>b;
       edge[a-1][b-1]=1;
    }

    /*//check input matrix and nodes
    for(int i=0; i<sizev+sizeu; ++i)
    {
        cout<<data[i].value<<' ';
        for(int j=0; j<sizev+sizeu; ++j) 
            cout<<edge[i][j]<<' ';
        cout<<'\n';
    }*/

    queue<int> index_queue;               //algorithm of maximum bipartite matching
    for(int i=0; i<sizev; ++i)
        index_queue.push(i);
    
    while(!index_queue.empty())
    {
        int w=index_queue.front();
        index_queue.pop();
        if(data[w].group==1)
        {
            for(int i=0; i<sizev+sizeu; ++i)
            {
                if(edge[w][i]==1)
                {
                    if(data[i].match==0)
                    {
                       data[i].match=data[w].value;
                       data[w].match=data[i].value;
                       //cout<<data[i].value<<' '<<data[i].match<<"    "<<data[w].value<<' '<<data[w].match<<'\n';
                       int v=w;
                       while(data[v].mark!=0)
                       {
                           
                           i=data[v].mark-1;
                           //cout<<"cancell"<<data[i].value<<data[i].match<<"    "<<data[v].value<<data[v].match<<'\n';
                           data[i].match=0;
                           //data[v].match=0;
                           
                           v=data[i].mark-1;
                           data[v].match=data[i].value;
                           data[i].match=data[v].value;
                          // cout<<data[i].value<<' '<<data[i].match<<"    "<<data[v].value<<' '<<data[v].match<<'\n';
                       }
                       while(!index_queue.empty())
                           index_queue.pop();
                       for(int k=0; k<sizev+sizeu; ++k)
                       {
                           data[k].mark=0;
                           if(data[k].group==1 && data[k].match==0)
                               index_queue.push(k);
                       }
                       break;
                    }
                    else
                        if(data[i].match!=data[w].value && data[i].mark==0)
                        {
                            index_queue.push(i);
                            data[i].mark=data[w].value;
                        }
                }

            }
        }
        else
        {
            data[data[w].match-1].mark=data[w].value;
            index_queue.push(data[w].match-1);
        }
    }

    for(int i=0; i<sizev; ++i)
    {

        if(data[i].match!=0)
            cout<<data[i].value<<' '<<data[i].match<<'\n';
    }
}





