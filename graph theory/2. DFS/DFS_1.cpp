// https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int team[MAXN];
bool impossible = false;

// DFS
// u: đỉnh hiện tại (học sinh)
// c: team cần gán (color)
void dfs(int u, int c) {
    team[u] = c;

    // Duyệt qua danh sách bạn của u
    for(int v : adj[u]) {
        // Nếu v chưa có team, gán v vào team ngược lại (3 - c)
        if(team[v] == 0) dfs(v, 3 - c);
        else if(team[v] == c) {
            // Nếu v đã có team mà trùng với u -> Mâu thuẫn
            impossible = true;
        }
    }
}



int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Duyệt qua tất cả các đỉnh để xử lý đồ thị không liên thông
    for(int i = 1; i <= n; i ++) {
        if(team[i] == 0) {
            dfs(i, 1); // Bắt đầu cho vào team 1, một thành phần liên thông
        }
    }

    if(impossible) cout << "IMPOSSIBLE\n";
    else {
        for(int i = 1; i <= n; i ++) {
            cout << team[i] << " ";
        }
        cout << endl;
    }

}