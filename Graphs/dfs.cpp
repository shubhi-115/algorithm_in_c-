#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
class Solve {
public:
  void startDfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storedfs) {
    vis[node] = 1;
    storedfs.push_back(node);
    for (int child : adj[node])
      if (!vis[child])
        startDfs(child, vis, adj, storedfs);
  }
  vector<int> dfsTraversal(int V, vector<int> adj[]) {
    vector<int> vis(V + 1, 0);
    vector<int> storedfs;
    for (int i = 0; i < V; i++)
      if (!vis[i])
        startDfs(i, vis, adj, storedfs);

    return storedfs;
  }
};
int main() {
  fast_io;
  int V, E; cin >> V >> E;
  vector<int> adj[V];
  for (int i = 0; i < E; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  Solve obj;
  vector<int> ans = obj.dfsTraversal(V, adj);
  for (int x : ans)
    cout << x << " ";
}
