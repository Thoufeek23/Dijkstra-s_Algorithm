#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <queue>

class Graph {
private:
    int V;
    std::vector<std::pair<int, int>>* adj;

public:
    Graph(int V);
    ~Graph();  // Destructor to free memory
    void addEdge(int u, int v, int w);
    void dijkstra(int src);
};

#endif // DIJKSTRA_H
