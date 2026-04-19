// https://cses.fi/problemset/task/1667

// BFS:
// - Tìm đường đi ngắn nhất trong đồ thị không trọng số
// - Kiểm tra tính liên thông
// - Tìm các thành phần liên thông

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
int n, m; // G = <V = n, E = m>
vector<int> parent(MAXN, -1); // Dùng để truy vết

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        // Nếu đã thăm đến n -> dừng lại
        if(u == n) break;

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                parent[v] = u;      // Đỉnh mà đi sang v là u (u -> v)
                q.push(v);
            }
        }
    }
}

int main() {
    if(!(cin >> n >> m)) return 0;

    for(int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    parent[1] = 0; // 1 không có cha -> cho cha của 1 là 0
    bfs(1);

    // Kiểm tra kết quả
    // Xem cha của n có tồn tại không
    // Cụ thể: xem có đỉnh nào đi sang n không
    if(parent[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    }
    // Nếu n có cha -> tồn tại đường đi từ 1 -> n
    // Tìm path đi từ 1 đến n
    else {
        
        // Path: Tìm cha của các đỉnh
        // Cụ thể: Tìm các đỉnh mà đi được đến đỉnh n
        vector<int> path;
        for(int v = n; v != 0; v = parent[v]) {
            path.push_back(v);
        }

        // Đảo ngược path
        reverse(begin(path), end(path));

        // Xuất ra đường đi ngắn nhất
        cout << size(path) << endl;
        
        // Xuất ra path từ 1 -> n
        for(int p : path) cout << p << " ";
    }
}