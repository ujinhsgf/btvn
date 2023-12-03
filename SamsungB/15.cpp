#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>>& adj) {
  int n = adj.size();
  vector<int> indegrees(n);
  for (int u = 0; u < n; u++) {
    for (int v : adj[u]) {
      indegrees[v]++;
    }
  }

  queue<int> queue;
  for (int u = 0; u < n; u++) {
    if (indegrees[u] == 0) {
      queue.push(u);
    }
  }

  vector<int> order;
  while (!queue.empty()) {
    int u = queue.front();
    queue.pop();
    order.push_back(u);
    for (int v : adj[u]) {
      indegrees[v]--;
      if (indegrees[v] == 0) {
        queue.push(v);
      }
    }
  }

  return order;
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

  vector<int> order = topologicalSort(adj);
  for (int u : order) {
    cout << u << " ";
  }
  cout << endl;
  return 0;
}

