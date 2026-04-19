// https://www.acwing.com/file_system/file/content/whole/index/content/12492995/

#include <bits/stdc++.h>
using namespace std;

// G = <V = r, E = c>
int r, c;
bool visited[45][45]; // Lưu tọa độ ô ghé thăm
int dist[45][45];     // dist[i][j] số bước từ (0, 0) đến (i, j)
vector<vector<char>> grid;

// Khởi tạo hướng đi
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// Hàm kiểm tra ô (x, y) có hợp lệ không
bool isValid(int x, int y) {
    if(x < 0 || x >= r || y < 0 || y >= c) return false; // ngoài phạm vi
    if(grid[x][y] == '#') return false; // ô tường
    if(visited[x][y]) return false;     // ô đã thăm

    return true;
}

int bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    dist[start_x][start_y] = 1; // Tính cả ô xuất phát

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if(x == r - 1 && y == c - 1) {
            return dist[x][y];
        }

        // Duyệt về 4 hướng
        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Nếu ô kề hợp lệ
            if(isValid(nx, ny)) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    if(!(cin >> r >> c)) return 0;
    grid.assign(r, vector<char>(c)); // r hàng, c cột

    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j ++) {
            cin >> grid[i][j];
        }
    }

    int ans = bfs(0, 0);
    cout << ans << endl;
}