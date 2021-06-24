//Bellman ford algorithm
#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inf (int)1e9
using namespace std;
struct node {
  int u;
  int v;
  int wt;
  node(int first, int second, int weight) {
    u = first;
    v = second;
    wt = weight;
  }

};
int main() {
  fast_io;
  int V, E; cin >> V >> E;

  vector<node> edges;
  while (E--) {
    int u, v, wt; cin >> u >> v >> wt;
    edges.push_back(node(u, v, wt));

  }
  int src; cin >> src;
  vector<int> dist(V, inf);
  dist[src] = 0;
  //Relaxing the edges N-1 times to get shortest distance
  for (int i = 1; i <= V - 1; i++) {
    for (node it : edges) {
      if (dist[it.u] + it.wt < dist[it.v])
        dist[it.v] = dist[it.u] + it.wt;
    }
  }
  bool flag = false;
  for (node it : edges) {
    if (dist[it.u] + it.wt < dist[it.v]) {
      flag = true;
      cout << "Negative Cycle Detected";
    }
  }
  if (!flag)
  {
    for (int i = 0; i < V; i++) cout << dist[i] << "\t";
  }
  return 0;
}
