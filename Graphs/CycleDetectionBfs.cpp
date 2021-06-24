// if topological sort is possible than it is DAG
#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
class Solution {
public:
  bool isCycle(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
      for (int it : adj[i])
        indegree[it]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      cnt++;
      for (int it : adj[node]) {
        indegree[it]--;
        if (indegree[it] == 0)
          q.push(it);
      }
    }
    if (cnt == V) return false;
    return true;
  }
};
int main() {
  fast_io;
  int V, E; cin >> V >> E;
  vector<int> adj[V];
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
