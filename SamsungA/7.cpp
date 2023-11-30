#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N][N], n, m, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void bfs(int x, int y, int c) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = u + dx[i], ny = v + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == c) {
                a[nx][ny] = -1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != -1) {
                ++cnt;
                bfs(i, j, a[i][j]);
            }
        }
    }
    cout << "Số lượng vùng liên thông trên ảnh là: " << cnt << endl;
    return 0;
}

