//when there is odd length of cycle than the graph is bipartite otherwise not
#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
class Solution {
public:
  bool bipartiteDfs(int node, vector<int> &col, vector<int> adj[]) {
    for (int it : adj[node]) {
      if (col[it] == -1)
      { col[it] = 1 - col[node];
        if (!bipartiteDfs(it, col, adj))
          return false;
      }
      else if (col[node] == col[it])
        return false;
    }
    return true;
  }
  bool checkBipartite(int V, vector<int> adj[]) {
    vector<int> col(V, -1);
    for (int i = 0; i < V; i++) {
      if (col[i] == -1)
      {
        col[i] = 1;
        if (!bipartiteDfs(i, col, adj))
          return false;
      }
    }
    return true;
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
  bool ans = obj.checkBipartite(V, adj);
  if (ans) cout << "Graph is Bipartite";
  else cout << "Graph is not Bipartite";

}
