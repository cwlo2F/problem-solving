#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Graph;

void root_tree(int here, Graph &graph, int *parent, bool *visited) {
    visited[here] = true;
    for (int next: graph[here]) {
        if (visited[next]) continue;
        parent[next] = here;
        root_tree(next, graph, parent, visited);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    Graph graph(n);
    int parent[200000];
    bool visited[200000];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    root_tree(0, graph, parent, visited); // root the tree from 0
    
    for (int i = 0; i < n; i++) cout << "vertex " << i << ": " << parent[i] << "\n";
    
    return 0;
}