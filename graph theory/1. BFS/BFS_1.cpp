// https://cses.fi/problemset/task/1666

// BFS:
// - Tìm đường đi ngắn nhất trong đồ thị không trọng số
// - Kiểm tra tính liên thông
// - Tìm các thành phần liên thông

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];      // Danh sách kề
bool visited[MAXN];  // Danh sách các đỉnh được thăm
vector<int> components;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {

    // G = <V = n, E = m>
    int n, m;
    if(!(cin >> n >> m)) return 0;

    // Nhập danh sách, tạo danh sách kề của các đỉnh
    for(int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Do đồ thị chưa liên thông, 
    // Nên duyệt từ đỉnh đầu đến đỉnh cuối để tìm thành phần liên thông
    // Một đồ thị liên thông nếu tồn tại đường đi giữa các đỉnh
    // Nếu chưa có đỉnh nào thì thêm vào, được thành phần liên thông mới
    for(int i = 1; i <= n; i ++) {
        // Nếu đỉnh i chưa được thăm
        if(!visited[i]) {
            // Thêm vào danh sách thành phần liên thông mới
            components.push_back(i);

            // Chạy bfs để đánh dấu các thành phố trong cụm này
            bfs(i);
        }
    }

    // TÌm số thành phần liên thông k
    int k = components.size() - 1;
    cout << k << endl;

    // Xuất ra các con đường cần xây thêm
    for(int i = 0; i < k; i ++) {
        cout << components[i] << " " << components[i + 1] << endl;
    }

}