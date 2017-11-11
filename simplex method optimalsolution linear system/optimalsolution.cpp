//practice for the optimal solution problem using simplex tableau page 272
//input:
/*
2 2            //number of unknowns & linear equations u and v, are slack variable which larger than 0
1 1 1 0 4      //equation 1 with rhs(last one) x, y, u, v, rhs
1 3 0 1 6      //equation 2 with rhs 
-3 -5 0 0 0    //target function z= 3x+5y+0u+0v rhs=0
*/

#include<cmath>
#include<iostream>

using namespace std;
const double inf=9999999;

int main()
{
	int sizev, sizee;
	cin>>sizev>>sizee;
	double simplex[sizee+1][sizev+sizee+1];
	for(int i=0; i<sizee+1; ++i)
		for(int j=0; j<sizev+sizee+1; ++j)
			cin>>simplex[i][j];
	/*
        //test the input matrix
	for(int i=0; i<sizee+1; ++i)
	{
		for(int j=0; j<sizev+sizee+1; ++j)
			cout<<simplex[i][j]<<' ';
		cout<<'\n';
	}
	*/
	//int count=0;
	//algorithm
	while(/*count!=3*/true)
	{
		double pivotv=0;
		int pivotj=0;
		for(int i=0; i<sizev+sizee; ++i)
		{
			if(simplex[sizee][i]<pivotv)
			{
				pivotv=simplex[sizee][i];
				pivotj=i;
			}
		}
                //count++;
		//cout<<pivotv<<" execute\n";
		if(pivotv==0)
			break;
		double theata=inf;
		int pivoti=0;
		for(int i=0; i<sizee; ++i)
		{
			if(simplex[i][pivotj]>0)
			{
				double temp=simplex[i][sizev+sizee]/simplex[i][pivotj];
				if(theata>temp)
				{
					theata=temp;
					pivoti=i;
				}
			}
		}
		if(theata==inf)
		{
			cout<<"not bounded\n";
			return 0;
		}
		double pivot=simplex[pivoti][pivotj];
		for(int i=0; i<sizev+sizee+1; ++i)
		{
			simplex[pivoti][i]/=pivot;
		}
		
		for(int i=0; i<sizee+1; ++i)
		{
			double c=simplex[i][pivotj];
			if(i!=pivoti)
				for(int j=0; j<sizev+sizee+1; ++j)
				{
					simplex[i][j]-=c*simplex[pivoti][j];
				}
		}
	}
	cout<<"the max value is: "<<simplex[sizee][sizev+sizee]<<'\n';
}






