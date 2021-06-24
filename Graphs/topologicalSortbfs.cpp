#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
class Solution {
public:
  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> topo;
    queue<int> q;
    vector<int> indegree(V + 1, 0);
    for (int i = 1; i <= V; i++)
      for (int it : adj[i])
        indegree[it]++;
    for (int i = 1; i <= V; i++)
      if (indegree[i] == 0)
        q.push(i);
    while (!q.empty()) {
      int node = q.front();
      topo.push_back(node);
      q.pop();
      for (int it : adj[node]) {
        indegree[it]--;
        if (indegree[it] == 0)
          q.push(it);
      }
    }
    return topo;
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
