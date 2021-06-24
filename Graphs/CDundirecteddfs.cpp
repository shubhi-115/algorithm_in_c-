#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
class Solution {
public:
  bool cycleDetection(int node, int par, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;
    for (int child : adj[node]) {
      if (!vis[child])
      {
        if (cycleDetection(child, node, adj, vis))
          return true;
      }
      else if (vis[child] && child != par)
        return true;
    }
    return false;
  }
  bool checkForCycle(int V, vector<int> adj[]) {
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++)
    { if (!vis[i])
      { if (cycleDetection(i, -1, adj, vis))
          return true;
      }
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
  bool ans = obj.checkForCycle(V, adj);
  if (ans) cout << "Cycle Present";
  else cout << "Cycle not Present";
  return 0;
}
