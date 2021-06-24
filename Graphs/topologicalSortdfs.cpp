#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
class Solution {
public:
  void findToposort(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    for (int it : adj[node]) {
      if (!vis[it])
        findToposort(it, vis, adj, st);
    }
    st.push(node);
  }
  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V + 1, 0);
    vector<int> res;
    stack<int> st;
    for (int i = 1; i <= V; i++) {
      if (!vis[i])
        findToposort(i, vis, adj, st);
    }
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    return res;
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
  vector<int> ans = obj.topoSort(V, adj);
  for (int s : ans) cout << s << " ";
  return 0;
}
