// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 1005;
vector<vector<char>> grid(MAXN);
int dist[MAXN][MAXN];       // Số bước từ A -> B
bool visited[MAXN][MAXN];
pair<int,int> parent[MAXN][MAXN];
char directions[MAXN][MAXN];

// Tọa độ di chuyển
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// Hàm check tọa độ có thỏa mãn hay không 
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && 
        grid[x][y] != '#' && !visited[x][y];
} 

// BFS tìm đường đi ngắn nhất từ A -> B
// Tọa độ bắt đầu là start_x, start_y
int bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    dist[start_x][start_y] = 0;

    while(!q.empty()) {
        auto[x, y] = q.front(); q.pop();

        if(grid[x][y] == 'B') return dist[x][y];

        // Duyệt về 4 hướng
        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Nếu ô kề hợp lệ và chưa thăm ô này
            if(isValid(nx, ny) && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                
                // Lưu tọa độ cha của ny, ny
                parent[nx][ny] = {x, y};

                // Lưu phương hướng khi từ x, y -> nx, ny
                if(nx == x + 1) directions[nx][ny] = 'D';
                else if(nx == x - 1) directions[nx][ny] = 'U';
                else if(ny == y + 1) directions[nx][ny] = 'R';
                else directions[nx][ny] = 'L';
            }
        }
    }
    return -1;
}


int main() {
    cin >> n >> m;
    grid.assign(n, vector<char>(m)); // n hàng,m cột

    int xA, yA, xB, yB;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <m; j ++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                xA = i;
                yA = j;
            }
            if(grid[i][j] == 'B') {
                xB = i;
                yB = j;
            }
        }
    }


    int length = bfs(xA, yA); // Đường ngắn nhất từ A -> B
    vector<char> path;
    int x = xB, y = yB;

    // Nếu không thăm được B
    if(length == -1) {
        cout << "NO";
        return 0;
    } 
    else cout << "YES" << endl;

    // Tìm path đi từ A -> B
    while(x != xA || y != yA) {
        path.push_back(directions[x][y]); // Lưu lại path sang x, y
        auto [px, py] = parent[x][y];     // Nhảy sang cha của x, y
        x = px, y = py;                   // Gán tọa độ cha x, y cho x, y
    }

    // Đảo ngược path 
    reverse(path.begin(), path.end());

    cout << length << endl;
    for(auto c : path) cout << c;
}