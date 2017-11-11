//practice of convex hull problem
/*input:
4       //total number of points
1 2     //pairs
2 1
3 4
4 3
*/
#include <iostream>
#include <vector>

using namespace std;

struct point{
	double x;
	double y;
};

void combine( int a[], int n, int m, int b[], const int M, vector<vector<int> >& result);    //from n inputs pick m: a is size n matrix contains n inputs. M=m. b: empty array of size m

int main()
{
	int size;
	point dataPoint;
	vector<vector<int> > combination;
	cin>>size;
	point data[size];
	for(int i=0; i<size; ++i)
	{
		cin>>data[i].x;
		cin>>data[i].y;
	}
        //check input:
	for(int i=0; i<size; ++i)
	{
		cout<<data[i].x<<' ';
		cout<<data[i].y<<' ';
		cout<<'\n';
	}
        //test combine function    
        int testcombine[5];
	testcombine[0]=1;
	testcombine[1]=2;
	testcombine[2]=3;
	testcombine[3]=4;
	testcombine[4]=5;    
	int bx[3];
	vector<vector<int> > result;
	combine(testcombine, 5, 3, bx, 3, result);  //from five inputs pick 3: 
        for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[0].size(); ++j)
			cout<<result[i][j]<<' ';
		cout<<'\n';
	}
	//convexhull
	int index[size];
	for(int i=0; i<size; ++i)
		index[i]=i;
	int b[2];
	combine(index, size, 2, b, 2, combination);
	//for(int i=0; i<combination.size(); ++i)
	//{
	//	for(int j=0; j<combination[0].size(); ++j)
	//		cout<<combination[i][j]<<' ';
	//	cout<<'\n';
	//}
	
	for(int i=0; i<combination.size(); ++i)
	{
		double x1=data[combination[i][0]].x;
		double y1=data[combination[i][0]].y;
		double x2=data[combination[i][1]].x;
		double y2=data[combination[i][1]].y;
		double a=y2-y1;
		double b=x1-x2;
		double c=x1*y2-y1*x2;
		double position, first;
                int counter=0;
		bool boundary=true;
		for(int j=0; j<size; ++j)
		{
			if(j!=combination[i][0] && j!=combination[i][1])
			{
				counter++;
				if(counter==1)
				{
					first=a*data[j].x+b*data[j].y-c;
					continue;
				}
				else
					position=a*data[j].x+b*data[j].y-c;
				
				if(first*position<0)
				{
					boundary=false;
					break;
				}
			}
				
		}
		if(boundary)
			cout<<combination[i][0]+1<<"  "<<combination[i][1]+1<<'\n';
	}
	
}

void combine( int a[], int n, int m, int b[], const int M, vector<vector<int> >& result )
  
{
  
	for(int i=n; i>=m; i--) 
  
	{
  
		b[m-1] = i - 1;
  
		if (m > 1)
  
		combine(a,i-1,m-1,b,M,result);
  
		else         
  
		{
			vector<int> temp;
  
			for(int j=M-1; j>=0; j--)
  
				temp.push_back(a[b[j]]);
  
			result.push_back(temp);
  
		}
  
	}
  
}
