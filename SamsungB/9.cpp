#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& path) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, path);
        }
    }
    path.push_back(u);
}

vector<int> eulerianPath(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> in(n), out(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            in[v]++;
            out[u]++;
        }
    }
    int start = 0, end = 0;
    for (int u = 0; u < n; u++) {
        if (in[u] + 1 == out[u]) {
            start = u;
        } else if (out[u] + 1 == in[u]) {
            end = u;
        }
    }
    if (start == 0 && end == 0) {
        for (int u = 0; u < n; u++) {
            if (out[u] > 0) {
                start = u;
                break;
            }
        }
    }
    vector<int> path;
    vector<bool> visited(n);
    dfs(start, adj, visited, path);
    reverse(path.begin(), path.end());
    if (path.size() != n + 1) {
        return {};
    }
    return path;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> path = eulerianPath(adj);
    if (path.empty()) {
        cout << "Khong ton tai chu trinh Euler trong do thi" << endl;
    } else {
        cout << "Chu trinh Euler trong do thi la: ";
        for (int u : path) {
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}

