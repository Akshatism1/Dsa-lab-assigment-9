
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V, E;

    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    int graph[100][100] = {0};

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[100], parent[100];
    bool visited[100] = {false};

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < V; count++) {
        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        if (u == -1 || key[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    cout << "\nMST Edges:\n";

    for (int i = 1; i < V; i++) {
        if (parent[i] == -1) {
            cout << "Graph is disconnected.";
            return 0;
        }

        cout << parent[i] << " - " << i
             << " : " << key[i] << endl;

        total += key[i];
    }

    cout << "Total MST Weight: " << total;

    return 0;
}
