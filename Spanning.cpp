//============================================================================
// Name        : assignment7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
using namespace std;
/*You have a business with several offices; you want to lease phone lines
to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities. You want a
set of lines that connects all your offices with a minimum total cost.
Solve the problem by suggesting appropriate data structures. */

class Object
{
	public:
		int key,value;
};


class Graph
{
	int **matrix;
	int n;
public:
	void create()
	{
		cout<<"\nEnter number of office = ";
		cin>>n;
		matrix = new int*[n];
		int i,j;
		for(i=0;i<n;i++)
		{
			matrix[i] = new int[n];
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<"\nEnter cost for office"<<i+1<<" and office"<<j+1<<" = ";
				cin>>matrix[i][j];
			}
		}
	}
	void show()
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<"|\t"<<matrix[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	Object getmin(vector<Object> p)
	{
		int min =p[0].value;
		int ind = 0;
		for(int i=0;i<(int)p.size();i++)
		{
			if(min>p[i].value)
			{
				min = p[i].value;
				ind = i;
			}
		}
		return p[ind];
	}
	int find(vector<int> p,int k)
	{
		for(int i=0;i<(int)p.size();i++)
		{
			if(k== p[i])
			{
				return 1;
			}
		}
		return 0;
	}
	void short_dist()
	{
		vector<Object> var;
		vector<int> visit;
		Object obj;
		int i,j;
		int min=0,cost=0;
		visit.push_back(0);
		while((int)visit.size()!=n)
		{
			for(j=0;j<(int)visit.size();j++)
			{
				for(i=0;i<n;i++)
				{
					if(matrix[visit[j]][i]!=0 && !find(visit,i))
					{
						obj.key = i;
						obj.value = matrix[visit[j]][i];
						var.push_back(obj);
					}
				}
			}
			obj = getmin(var);
			min = obj.key;
			if(!find(visit,min))
			{
				visit.push_back(min);
				cost = cost + obj.value;
			}
			while(!var.empty())
			{
				var.pop_back();
			}
		}
		cout<<"\nCost = "<<cost;
	}
};

int main() {
	Graph list;
	list.create();
	list.show();
	list.short_dist();
	return 0;
}
