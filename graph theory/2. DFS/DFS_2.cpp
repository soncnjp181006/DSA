//

// Chu trình: 
// Bắt đầu từ một đỉnh
// Đi qua các cạnh (không phải tất cả)
// Các đỉnh, cạnh đã đi qua không được đi lại lần thứ 2 (> 2)
// Không lặp đỉnh, ngoại trừ đỉnh đầu = đỉnh cuối

// Thuật toán:
// visited[u] đánh dấu đỉnh đã thăm
// parent[u] lưu cha của đỉnh u trong cây DFS
// onStack[u] đánh dấu đỉnh đang nằm trên đường đi DFS hiện tại
// Khi phát hiện chu trình:
//      - Khi đang ở đỉnh u -> Xét hàng xóm v:
//          + Nếu v chưa thăm: DFS tiếp, parent[v] = u
//          + Nếu v đã thăm và v != parent[u] -> Tìm thấy chu trình
// Dựng lại chu trình:
//      - Khi phát hiện chu trình từ u đến v (v đã thăm):
//          + Lật ngược u theo parent[] đến khi gặp v
//          + Thêm v vào cuối để đóng chu trình

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
bool visited[MAXN];
int parent[MAXN];
vector<int> adj[MAXN];
vector<int> cycle;
bool checkCycle = false;

// Đỉnh u, parent là p
void dfs(int u, int p) {
    visited[u] = true;
    parent[u] = p;

    for(int v : adj[u]) {
        if(checkCycle) return; // Đã tìm thấy chu trình 

        if(!visited[v]) {
            dfs(v, u); // u là parent của v
        }
        else if(v != p && !checkCycle) {
            // Tìm thấy chu trình
            // v đã thăm không phải cha của u
            // Dựng lại chu trình từ u ngược về v
            cycle.push_back(v);
            int cur = u;
            while(cur != v) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(v); // Đóng chu trình
            checkCycle = true;
            return;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // DFS từng đỉnh chưa thăm
    for(int i = 1; i <= n && !checkCycle; i ++) {
        if(!visited[i]) {
            dfs(i, -1);
        }
    }

    if(!checkCycle) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << cycle.size() << endl;
        for(int x : cycle) {
            cout << x << " ";
        }
        cout << endl;
    }
}