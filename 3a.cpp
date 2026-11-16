
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100];

int findParent(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

void unite(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    parent[pu] = pv;
}

int main() {
    int V, E;

    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    for (int i = 0; i < V; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), compare);

    int total = 0;
    int count = 0;

    cout << "\nMST Edges:\n";

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(u) != findParent(v)) {
            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            total += edges[i].weight;
            unite(u, v);
            count++;
        }
    }

    if (count != V - 1) {
        cout << "Graph is disconnected. MST does not exist.";
    }
    else {
        cout << "Total MST Weight: " << total;
    }

    return 0;
}
