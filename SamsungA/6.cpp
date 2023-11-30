#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int low[N], num[N], parent[N], counter = 0;

void dfs(int u) {
    low[u] = num[u] = ++counter;
    for (int v : adj[u]) {
        if (!num[v]) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) {
                cout << "Edge " << u << " - " << v << " is a bridge\n";
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    return 0;
}

