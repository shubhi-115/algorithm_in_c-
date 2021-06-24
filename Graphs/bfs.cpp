#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
//nodes are starting from 0 to V-1
class Solve {
public:
  vector<int> bfsTraversal(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<int> vis(V, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
      int node = q.front();
      bfs.push_back(node);
      q.pop();
      for (int x : adj[node]) {
        if (!vis[x]) {
          q.push(x);
          vis[x] = 1;
        }
      }
    }
    for (int i = 0; i < V; i++) cout << dis[i] << " ";
    return bfs;
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
  vector<int> ans = obj.bfsTraversal(V, adj);
  for (int x : ans)
    cout << x << " ";
}
