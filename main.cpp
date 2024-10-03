#include "dijkstra.h"
#include <iostream>

using namespace std;

int main() {
    int V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    if (V <= 0) {
        cout << "Number of vertices must be positive." << endl;
        return 1;
    }

    Graph g(V);

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter edges in the format (u v w) where u and v are the vertices and w is the weight:\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    g.dijkstra(source);

    return 0;
}
