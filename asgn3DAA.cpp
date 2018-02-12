#include <bits/stdc++.h>
using namespace std; 

typedef struct edgeTable{
	int u; 
	int v;
	int value;
}edgeTable;

typedef struct edgeInput{
	int vert;
	int weight; 
	struct edgeInput * next;
}edgeInput;

int main()
{
	int countVert, joined;  
	edgeInput ed[10]; 
	edgeInput *e ; 
	cout<<"Enter the number of vertices";
	cin>>countVert;  	
	for (int i = 0; i < countVert; i++)
	{
		cout<<"Enter the number of vertices joined to " <<i+1;
		cin>>joined;

		cout<<"enter the vertices and their weight";
		//new edgeInput	
			e = new edgeInput; 
			cin>>ed>>w;
			e->vert = ed; 
			e->weight = w;
			if (ed[i].next == NULL)
			{
				ed[i] = e; 	
			}
			else{

			} 


		  

	}
	return 0;
}