#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 0x7fffffffLL

typedef unsigned long long Weight;

struct WeightedVertex{
    int v;
    Weight w;
};

bool operator>(WeightedVertex a, WeightedVertex b) {
    if (a.w != b.w) return a.w > b.w;
    return a.v > b.v;
}

void dijkstra(int start, int n, vector<Weight> &f, vector<vector<WeightedVertex>> &graph) {
    for (int i = 0; i < n; i++) f[i] = INF;
    priority_queue<WeightedVertex, vector<WeightedVertex>, greater<WeightedVertex>> pq;

    f[start] = 0;
    pq.push(WeightedVertex{start, 0});
    while (!pq.empty()) {
        WeightedVertex here = pq.top();
        pq.pop();
        if (f[here.v] > here.w) continue;
        for (auto next: graph[here.v]) {
            Weight tmp = f[here.v] + next.w;
            if (tmp < f[next.v]) {
                f[next.v] = tmp;
                pq.push(WeightedVertex{next.v, tmp});
            }
        }
    }

    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<WeightedVertex>> graph(n);
    vector<Weight> f(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        Weight w;
        cin >> u >> v >> w;
        graph[u].push_back(WeightedVertex{v, w});
    }
    
    dijkstra(0, n, f, graph);
    
    for (int i = 0; i < n; i++) cout << i << ": " << f[i] << "\n";
    return 0;
}