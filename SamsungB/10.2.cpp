#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, st);
        }
    }
    st.push(u);
}

void reverseEdges(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<vector<int>> revAdj(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            revAdj[v].push_back(u);
        }
    }
    adj = revAdj;
}

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& scc) {
    visited[u] = true;
    scc.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, scc);
        }
    }
}

vector<vector<int>> kosaraju(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n);
    stack<int> st;
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            dfs(u, adj, visited, st);
        }
    }
    reverseEdges(adj);
    vector<vector<int>> sccs;
    visited.assign(n, false);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            vector<int> scc;
            dfs(u, adj, visited, scc);
            sccs.push_back(scc);
        }
    }
    return sccs;
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
    vector<vector<int>> sccs = kosaraju(adj);
    cout << "Cac thanh phan lien thong manh la:" << endl;
    for (vector<int>& scc : sccs) {
        for (int u : scc) {
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}

