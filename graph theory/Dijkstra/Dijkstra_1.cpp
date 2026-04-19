// https://loj.ac/p/119
// Dijkstra - tìm đường đi ngắn nhất trên đồ thị có trọng số >= 0

// Bước 1: Khởi tạo
//   - dist[s] = 0
//   - dist[u] = ∞ với mọi u ≠ s
//   - visited[u] = false với mọi u
//   - Push (0, s) vào heap

// Bước 2: Lặp cho đến khi heap rỗng
//   - Lấy đỉnh u có dist nhỏ nhất từ heap
//   - Nếu u đã visited → bỏ qua
//   - Đánh dấu visited[u] = true
//   - Với mỗi đỉnh v kề u:
//       + Nếu dist[u] + weight(u,v) < dist[v]:
//         * Cập nhật dist[v] = dist[u] + weight(u,v)
//         * Push (dist[v], v) vào heap

// Bước 3: Trả về dist[t]

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

int main() {
    // G = <V= n , E = m>
    // Tìm đường đi ngắn nhất từ đỉnh s tới đỉnh t
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    // adj[u] = list {v, w}
    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 1; i <= m; i ++) {
        int u, v, w; // (u, v) và weight
        cin >> u >> v >> w;

        // Đồ thị vô hướng -> thêm cả hai chiều
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // dist[u] = min distance(s, u)
    vector<ll> dist(n + 1, INF);
    dist[s] = 0;

    // visited[u] = true nếu đã chốt dist[u]
    vector<bool> visited(n + 1, false);

    // min heap: {khoảng cách, đỉnh}
    // greater<> để heap là min heap
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        // Lấy đỉnh có khoảng cách nhỏ nhất
        auto [d, u] = pq.top();
        pq.pop();

        // Nếu đã xét rồi thì bỏ qua
        if(visited[u]) continue;

        // Chốt đỉnh u
        visited[u] = true;

        // Cập nhật khoảng cách các đỉnh kề
        for(auto [v, w] : adj[u]) {
            // relaxation: nếu đi qua đỉnh u tốt hơn
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[t] << endl;
}