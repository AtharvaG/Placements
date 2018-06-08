#include <bits/stdc++.h>

using namespace std;

class graph{
	int V;
	vector<int> *adj;
	int *arr; 
	public:
		graph(int V){
			this->V = V;
			adj = new vector<int>[V];
			arr = new int [V];
			for(int i = 0; i< V; i++)
				arr[i] = 0;

		}

		void addEdge(int u, int v){
			adj[u].push_back(v);
		}

		void display(){

		}
		void bfs(int s){
			int array[V];
			for(int i=0; i< V; i++)  
				array[i] = 0;

			array[s] = 1;

			queue<int> q; 
			q.push(s);
			vector<int>::iterator it; 
			while(!q.empty()){
				int temp = q.front();
				cout<<temp<<" ";
				q.pop();

				for(it = adj[temp].begin(); it < adj[temp].end(); ++it){
					if(!array[*it]){
						array[*it] = 1; 
						q.push(*it);
					}
				}
			}
		}


		void dfs(int s){


			arr[s] = 1;
			cout<<s<<" ";
			

			std::vector<int>::iterator it; 

			for(it = adj[s].begin(); it< adj[s].end(); ++it){
				if(!arr[*it]){
					dfs(*it); 
				}
			}

		}
};







int main(){

	graph g(4);

	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.bfs(2);
    g.dfs(2);

}
