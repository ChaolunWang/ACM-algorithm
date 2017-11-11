//practice for the shortest-augmenting-path problem page 283
//input:
/*
6           //number of vertex
1 2 3 4 5 6 //vertex
7           //number of edges
1 2 2       //edges: start end maxflow
1 4 3
2 3 5
4 3 1
2 5 3
3 6 2
5 6 4
*/

#include<cmath>
#include<iostream>
#include<queue>

const int inf=1879048191;

using namespace std;

struct edge
{
	int start;
	int end;
	int max;
	int current; 
};

struct vertex
{
	int id;
	int flow;
	int from;
};

int main()
{
	int sizee, sizev;
	cin>>sizev;
	vertex nodes[sizev];
	for(int i=0; i<sizev; ++i)
	{
		cin>>nodes[i].id;
		if(!i)
			nodes[i].flow=inf;
		else
			nodes[i].flow=0;
		nodes[i].from=0;
	}
	cin>>sizee;
	edge pass[sizee];
	for(int i=0; i<sizee; ++i)
	{
		cin>>pass[i].start;
		cin>>pass[i].end;
		cin>>pass[i].max;
		pass[i].current=0;
	}

	//algorithm
	queue<int> index_queue;
	index_queue.push(1);

	while(!index_queue.empty())
	{
		int i=index_queue.front();
               // cout<<i<<'\n';
		index_queue.pop();
		for(int k=0; k<sizee; ++k)
		{
			if(pass[k].start==i && nodes[pass[k].end-1].from==0 && (!(nodes[pass[k].end-1].flow==inf)))
			{
				int r=pass[k].max-pass[k].current;
				if(r>0)
				{
					int l=min(nodes[i-1].flow, r);
					nodes[pass[k].end-1].from=i;
					nodes[pass[k].end-1].flow=l;
					index_queue.push(pass[k].end);
				}
			}
			else if(pass[k].end==i && nodes[pass[k].start-1].from==0 && (!(nodes[pass[k].start-1].flow==inf)) && pass[k].current>0)
			{
				int l=min(nodes[i-1].flow, pass[k].current);
				nodes[pass[k].start-1].from=i*(-1);
				nodes[pass[k].start-1].flow=l;	
				index_queue.push(pass[k].start);			
			}
		}
		if(!nodes[sizev-1].from==0)
		{
			int j=nodes[sizev-1].id;
			//cout<<"execute\n";
			while(!(j==1))
			{
				//cout<<j<<' ';
				if(nodes[j-1].from>0)
				{
					for(int k=0; k<sizee; ++k)
						if(pass[k].start==nodes[j-1].from && pass[k].end==j)
							pass[k].current+=nodes[sizev-1].flow;
					j=nodes[j-1].from;
				}
				else
				{
					for(int k=0; k<sizee; ++k)
						if(pass[k].start==j && pass[k].end==nodes[j-1].from*(-1))
							pass[k].current-=nodes[sizev-1].flow;	
					j=nodes[j-1].from*(-1);				
				}
			}
			for(int i=1; i<sizev; ++i)
			{
				nodes[i].flow=0;
				nodes[i].from=0;
			}
			while(!index_queue.empty())
				index_queue.pop();
			index_queue.push(1);
		}
	}

	int x=0;
	for(int k=0; k<sizee; ++k)
	{
		if(pass[k].start==1)
			x+=pass[k].current;
		else if(pass[k].end==1)
			x-=pass[k].current;
	}
	cout<<"the max flow is: "<<x<<'\n';	
}




