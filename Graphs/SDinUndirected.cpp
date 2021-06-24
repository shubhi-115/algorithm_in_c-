//when there is odd length of cycle than the graph is bipartite otherwise not
#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
class Solution {
public:
  void BFS(vector<int> adj[], int N, int src)
  {
    int dist[N];
    for (int i = 0; i < N; i++) dist[i] = INT_MAX;
    queue<int>  q;

    dist[src] = 0;
    q.push(src);

    while (q.empty() == false)
    {
      int node = q.front();
      q.pop();

      for (auto it : adj[node]) {
        if (dist[node] + 1 < dist[it]) {
          dist[it] = dist[node] + 1;
          q.push(it);
        }
      }
    }
    for (int i = 0; i < N; i++) cout << dist[i] << " ";

  }

};
int main() {
  fast_io;
  int V, E; cin >> V >> E;
  vector<int> adj[V];
  while (E--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  Solution obj;
  obj.BFS(adj, V, 0);
  return 0;
}
