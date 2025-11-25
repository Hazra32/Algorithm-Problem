#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  
    while (T--) {
        int N, M;
        cin >> N >> M;

        
        vector<vector<Edge>> graph(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});  
        }

        
        vector<long long> dist1(N + 1, INF);
        vector<long long> dist2(N + 1, INF);
        dist1[1] = 0;

        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist2[u]) continue;  

            for (auto &edge : graph[u]) {
                int v = edge.to;
                long long new_dist = d + edge.weight;

                if (new_dist < dist1[v]) {
                    dist2[v] = dist1[v];
                    dist1[v] = new_dist;
                    pq.push({new_dist, v});
                } else if (new_dist > dist1[v] && new_dist < dist2[v]) {
                    dist2[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }

        cout << dist2[N] << "\n";  
    }

    return 0;
}

