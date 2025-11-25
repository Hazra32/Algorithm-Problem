#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int c;
    cin >> c;  // number of test cases

    while(c--) {
        int n, m;
        cin >> n >> m;  // number of nodes and edges

        vector<Edge> edges(m);
        for(int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }

        // Initialize distances
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        // Relax all edges n-1 times
        for(int i = 1; i <= n-1; i++) {
            for(auto &e : edges) {
                if(dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        // Check for negative cycle
        bool negative_cycle = false;
        for(auto &e : edges) {
            if(dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
                negative_cycle = true;
                break;
            }
        }

        if(negative_cycle)
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }

    return 0;
}

