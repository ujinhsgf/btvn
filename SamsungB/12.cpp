#include <iostream>
#include <vector>

using namespace std;

bool hasUniqueTopologicalOrder(vector<vector<int>>& adj) {
  int n = adj.size();
  vector<int> indegrees(n);
  for (int u = 0; u < n; u++) {
    for (int v : adj[u]) {
      indegrees[v]++;
    }
  }
  vector<int> order;
  for (int u = 0; u < n; u++) {
    if (indegrees[u] == 0) {
      order.push_back(u);
    }
  }
  for (int i = 0; i < n - 1; i++) {
  int u = order[i], v = order[i + 1];
  bool found = false;
  for (int w : adj[u]) {
    if (w == v) {
      found = true;
      break;
    }
  }
  if (!found) {
    return false;
  }
}
  return true;
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
  if (hasUniqueTopologicalOrder(adj)) {
    cout << "Do thi co toan bo cac thu tu topo duy nhat" << endl;
  } else {
    cout << "Do thi co it nhat mot thu tu topo khac" << endl;
  }
  return 0;
}

