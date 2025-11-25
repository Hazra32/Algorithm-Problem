#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;  

int main() {
    int n, m;
    cin >> n >> m;

    
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w}); 
    }

vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);


  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;


  dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        if (u == n) break; 

        for (auto [v, w] : graph[u]) {
            if (!visited[v] && d + w < dist[v]) {
                dist[v] = d + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }


  if (dist[n] == INF) {
        cout << -1 << endl;
    } else {

      vector<int> path;
        int v = n;
        while (v != -1) {
            path.push_back(v);
            v = parent[v];
        }
        reverse(path.begin(), path.end());


      for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

