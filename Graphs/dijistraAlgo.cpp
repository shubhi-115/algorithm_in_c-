//Dijistra Algorithm

#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inf (int)1e9
using namespace std;

int main() {
  fast_io;
  int V, E; cin >> V >> E;
  vector<pair<int, int>> adj[V + 1];
  while (E--) {
    int u, v, wt; cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }
  vector<int> dist(V + 1, inf);
  int src; cin >> src;
  dist[src] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//min heap=> pair{dist,from}
  pq.push({0, src});
  while (!pq.empty()) {
    int node = pq.top().second;
    int dis = pq.top().first;
    pq.pop();
    for (auto it : adj[node]) {
      if (dis + it.second < dist[it.first])
      {
        dist[it.first] = dis + it.second;
        pq.push({dist[it.first], it.first});// kya push kra hai
      }

    }
  }
  for (int i = 1; i <= V; i++)
    cout << dist[i] << " ";
  return 0;
}

