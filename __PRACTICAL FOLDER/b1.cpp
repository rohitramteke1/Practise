#include <iostream>
#include <vector>
#include <iterator>
#include <list>
using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

// Create a graph with given vertices, and maintain an adjacency list
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;

    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " \n";
        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

// Adjacency matrix
vector<vector<int> > adj;
void addEdge(int x, int y)
{
	adj[x][y] = 1;
	adj[y][x] = 1;
}

void DFS(int start, vector<bool>& visited)
{
	cout << start << " ";
	visited[start] = true;
	for (int i = 0; i < adj[start].size(); i++) {
		if (adj[start][i] == 1 && (!visited[i])) {
			DFS(i, visited);
		}
	}
}

void __BFS__main(){
    int vertices;
    cout << "Enter the number of vertices\n";
    cin >> vertices;
    Graph g(vertices);
    cout << "Enter the number of edges that we want to connect\n";
    int edges;
    cin >> edges;
    for (int i = 1; i <= edges; i++)
    {
        int a, b;
        cout << "Enter the pair(i, j) i.e. vertex, edge \n";
        cin >> a >> b;
        g.addEdge(a, b);
    }
    // By default we're starting from 0 vertex
    g.BFS(0);
    cout << endl ;
}

void __DFS__main(){
    int v, e;
    cout << "Enter the number of vertices and edges\n";
    cin >> v >> e ;

	adj = vector<vector<int> >(v, vector<int>(v, 0));

    for (int i = 1; i <= e; i++)
    {
        addEdge(0, i);
    }
	vector<bool> visited(v, false);
	// By default we're starting from 0 vertex
	DFS(0, visited);
}

int main()
{
    int choice;
    char ch;
    do{
        cout <<"Enter the choice\n";
        cout << "\n1. BFS : \n2. DFS :\n3. Exit(0)\n";
        cin >> choice ;
        switch(choice)
        {
            case 1:
                __BFS__main();
                break;
            case 2:
                __DFS__main();
                break;
            case 3:
                exit(0);
            default:
                cout << "Wrong choice\n";
                break;
        }
        cout << "\nWant to enter more(y/Y)\n";
        cin >> ch ;
    }while(ch == 'y' || ch == 'Y');
    return 0;
}