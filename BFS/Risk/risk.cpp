#include <bits/stdc++.h>
using namespace std;

const int MAX_COUNTRIES = 21; // countries numbered 1..20

int main() {
    int testSet = 1;

    while (true) {
        vector<int> graph[MAX_COUNTRIES];
        int neighbors;

        // Step 1: Read the map (19 countries)
        for (int i = 1; i <= 19; i++) {
            if (!(cin >> neighbors)) return 0; // EOF
            graph[i].clear();
            for (int j = 0; j < neighbors; j++) {
                int neighbor;
                cin >> neighbor;
                graph[i].push_back(neighbor);
                graph[neighbor].push_back(i); // undirected graph
            }
        }

        int N; // number of queries
        if (!(cin >> N)) break;
        vector<pair<int,int>> queries(N);
        for (int i = 0; i < N; i++) {
            cin >> queries[i].first >> queries[i].second;
        }

        cout << "Test Set #" << testSet++ << "\n";

        // Step 2: Process each query using BFS
        for (auto &q : queries) {
            int start = q.first, dest = q.second;
            vector<int> distance(MAX_COUNTRIES, -1);
            vector<bool> visited(MAX_COUNTRIES, false);
            queue<int> Q;

            Q.push(start);
            visited[start] = true;
            distance[start] = 0;

            while (!Q.empty()) {
                int curr = Q.front(); Q.pop();
                if (curr == dest) break;

                for (int neighbor : graph[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        distance[neighbor] = distance[curr] + 1;
                        Q.push(neighbor);
                    }
                }
            }

            // Step 3: Print result
            cout << setw(2) << start << " to " << setw(2) << dest << ": " << distance[dest] << "\n";
        }

        cout << "\n"; // blank line after each test set
    }

    return 0;
}
