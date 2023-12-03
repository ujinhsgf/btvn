#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1);
    dfs(v, adj, visited);
    cout << "Cac dinh thuoc thanh phan lien thong manh chua dinh " << v << " la: ";
    for (int u = 1; u <= n; u++) {
        if (visited[u]) {
            cout << u << " ";
        }
    }
    cout << endl;
    return 0;
}

