#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
class Solution {
public:
  bool cycleDetection(int src, int V, vector<int> &vis, vector<int> adj[]) {
    // vector<int> parent(V + 1, -1);
    queue<pair<int, int>> q;
    vis[src] = 1;

    q.push({src, -1});
    while (!q.empty()) {
      int node = q.front().first;
      int par = q.front().second;
      q.pop();
      for (auto it : adj[node]) {
        if (!vis[it])
        {
          vis[it] = 1;
          q.push({it, node});
        }
        else if (par != it) return true;
      }
    }
    return false;
  }
  bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V + 1, 0);
    for (int i = 1; i < V; i++) {
      if (!vis[i])
        if (cycleDetection(i, V, vis, adj)) return true;
    }
    return false;
  }
};
int main() {
  fast_io;
  int V, E; cin >> V >> E;
  vector<int> adj[V + 1];
  while (E--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  Solution obj;
  bool ans = obj.isCycle(V, adj);
  if (ans) cout << "Cycle Present";
  else cout << "Cycle not present";
  return 0;
}
