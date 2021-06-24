#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
class Solution {
public:
  bool cycleDetection(int node, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[]) {
    vis[node] = 1;
    dfsvis[node] = 1;
    for (int child : adj[node]) {
      if (!vis[child]) {
        if (cycleDetection(child, vis, dfsvis, adj))
          return true;
      } else if (vis[child] && dfsvis[child])
        return true;
    }
    return false;
  }
  bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V + 1, 0);
    vector<int> dfsvis(V + 1, 0);
    for (int i = 1; i <= V; i++)
      if (!vis[i])
        if (cycleDetection(1, vis, dfsvis, adj)) return true;

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
    // adj[v].push_back(u);
  }
  Solution obj;
  bool ans = obj.isCycle(V, adj);
  if (ans) cout << "Cycle Present";
  else cout << "Cycle not present";
  return 0;
}
