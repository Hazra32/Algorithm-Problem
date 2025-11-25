#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;              
        if (n == 0) break;    
        int l;
        cin >> l;              

        vector<vector<int>> graph(n);

       
        for (int i = 0; i < l; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> color(n, -1); 
        queue<int> q;

        color[0] = 0;  
        q.push(0);

        bool isBipartite = true;

        
        while (!q.empty() && isBipartite) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (color[v] == -1) {
                    
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                   
                    isBipartite = false;
                    break;
                }
            }
        }

       
        if (isBipartite)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }

    return 0;
}

