#pragma		once
#include <vector> 

class Graph {
public:
	
	// initializes an undirected graph that can store at most n vertices
	Graph(const int n) {
		for (int i = 0; i < 400; i++)
			for (int k = 0; k < 400; k++)
				a[i][k] = 0;
	}

	
	// inserts an edge between vertices u and v
	void insertEdge(int u, int v) {
		a[u][v] = 1; 
		a[v][u] = 1; 

	}


	// returns the set of vertices that are adjacent to v
	std::vector<int> adjacentVertices(int v) {
		std::vector<int> vertices;
		for (int i = 0; i < 400; i++) 
		{
			if (a[v][i] == 1)
			{
				vertices.push_back(i);
			}
		}
		return vertices;
	}

	
	// return a list of vertices that appear between v and w, starting with v and ending with w
	std::vector<int> getPath(int v, int w) {
		int position = v;
		std::vector<int> path;
		std::vector<int> visited; 
		std::vector <int> possibleRoute = adjacentVertices(v);

		path.push_back(position);
		visited.push_back(position);

		while (position != w)
		{
			
			if (wasVisited(possibleRoute[0], visited ) == 0){
			position = possibleRoute[0];
			possibleRoute = adjacentVertices(position);
			path.push_back(position);
			visited.push_back(position);
			
			}
			else {
				int k = 0;
				while (wasVisited(possibleRoute[k], visited) == 1) {
					if (k < (possibleRoute.size()-1)) {
						k++;
					}
					else {
						k = 0; 
						path.pop_back(); 
						position = path.back(); 
						possibleRoute = adjacentVertices(position); 
						
					}
				}
				position = possibleRoute[k];
				possibleRoute = adjacentVertices(position);
				path.push_back(position);
				visited.push_back(position);
			
			}
		}

		return path;
	}

private:
	// member variables and functions to implement the public member functions
	int a[400][400];

	bool wasVisited(int station, std::vector <int> Visited)
	{
		for (int i = 0; i < Visited.size(); i++)
		{
			if (station == Visited[i])
				return 1;
		}
		return 0; 
	}
};
