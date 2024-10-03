#include "dijkstra.h"

using namespace std;

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<pair<int, int>>[V];
}

Graph::~Graph() {
    delete[] adj; // Free allocated memory for adjacency list
}

void Graph::addEdge(int u, int v, int w) {
    if (u >= 0 && u < V && v >= 0 && v < V) {  // Check for valid vertex indices
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
}

void Graph::dijkstra(int src) {
    if (src < 0 || src >= V) {  // Check for valid source index
        cout << "Invalid source vertex." << endl;
        return;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, numeric_limits<int>::max());
    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << "Vertex Distance from Source (" << src << ")\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << (dist[i] == numeric_limits<int>::max() ? -1 : dist[i]) << endl;
    }
}
