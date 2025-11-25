#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, r;
    int caseNum = 1;
    while (cin >> n) {
        vector<int> busyness(n + 1);
        for (int i = 1; i <= n; i++) cin >> busyness[i];

        cin >> r;
        vector<Edge> edges(r);
        for (int i = 0; i < r; i++) {
            cin >> edges[i].u >> edges[i].v;
            int w = busyness[edges[i].v] - busyness[edges[i].u];
            edges[i].w = w * w * w; // cubic cost
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; i++) cin >> queries[i];

        // Initialize distances
        const long long INF = 1e15;
        vector<long long> dist(n + 1, INF);
        dist[1] = 0;

        vector<bool> inCycle(n + 1, false);

        // Bellman-Ford
        for (int i = 1; i <= n - 1; i++) {
            for (auto &e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        // Detect negative cycles
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                inCycle[e.v] = true;
            }
        }

        // Propagate negative cycle influence
        queue<int> qCycle;
        for (int i = 1; i <= n; i++)
            if (inCycle[i]) qCycle.push(i);

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) adj[e.u].push_back(e.v);

        while (!qCycle.empty()) {
            int u = qCycle.front(); qCycle.pop();
            for (int v : adj[u]) {
                if (!inCycle[v]) {
                    inCycle[v] = true;
                    qCycle.push(v);
                }
            }
        }

        // Output results
        cout << "Set #" << caseNum++ << "\n";
        for (int node : queries) {
            if (dist[node] < 3 || dist[node] == INF || inCycle[node]) cout << "?\n";
            else cout << dist[node] << "\n";
        }
    }
    return 0;
}

