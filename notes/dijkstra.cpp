#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF (1LL << 60)

typedef unsigned long long Weight;

struct WeightedVertex{
    int v;
    Weight w;
};

bool operator>(WeightedVertex a, WeightedVertex b) {
    if (a.w != b.w) return a.w > b.w;
    return a.v > b.v;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<WeightedVertex>> graph(n);
    vector<unsigned long long> f(n);
    for (int i = 0; i < n; i++) f[i] = INF;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        unsigned long long w;
        cin >> u >> v >> w;
        graph[u].push_back(WeightedVertex{v, w});
    }
    
    priority_queue<WeightedVertex, vector<WeightedVertex>, greater<WeightedVertex>> pq;
    
    f[0] = 0;
    pq.push(WeightedVertex{0, 0});

    while(!pq.empty()) {
        WeightedVertex x = pq.top();
        pq.pop();
        if (x.w > f[x.v]) continue;
        if (f[x.v] >= INF) break;
        for (auto next: graph[x.v]) {
            unsigned long long tmp = f[x.v] + next.w;
            if (tmp < f[next.v]) {
                f[next.v] = tmp;
                pq.push(WeightedVertex{next.v, tmp});
            }
        }
    }
    for (int i = 0; i < n; i++) cout << i << ": " << f[i] << "\n";
    return 0;

}