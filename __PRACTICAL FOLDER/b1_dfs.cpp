#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
void addEdge(int x, int y)
{
	adj[x][y] = 1;
	adj[y][x] = 1;
}
void dfs(int start, vector<bool>& visited)
{
	cout << start << " ";
	visited[start] = true;
	for (int i = 0; i < adj[start].size(); i++) {
		if (adj[start][i] == 1 && (!visited[i])) {
			dfs(i, visited);
		}
	}
}

int main()
{
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
	dfs(0, visited);
    return 0;
}