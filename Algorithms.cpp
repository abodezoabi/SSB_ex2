/*
 * ID: 211407424
 * abodezoabi2000@gmail.com
 */

#include "Algorithms.hpp"
#include "Graph.hpp"
#include <queue>
#include <unordered_map>
#include <iostream>
#include <climits>
#include <algorithm>
namespace ariel {

    // Check if the graph is connected using BFS
    bool Algorithms::isConnected(ariel::Graph g) {
        int n = g.getNumVertices();
        std::vector<bool> visited(static_cast<std::vector<bool>::size_type>(n), false);

        // Define BFS lambda function for traversal
        auto bfs = [&](int start) {
            std::queue<int> q;
            q.push(start);
            visited[static_cast<std::vector<bool>::size_type>(start)] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                // Traverse neighbors of the current vertex
                for (int v = 0; v < n; v++) {
                    if (g.getAdjacency(u, v) && !visited[static_cast<size_t>(v)]) {
                        visited[static_cast<size_t>(v)] = true;
                        q.push(v);
                    }
                }
            }
        };

        // Perform BFS traversal from the first vertex
        bfs(0);

        // Check if all vertices are visited
        for (bool v: visited) {
            if (!v) {
                return false;
            }
        }

        return true;
    }

    // Find the shortest path using BFS
    std::string Algorithms::shortestPath(Graph g, int start, int end) {
        size_t numVertices = (size_t)g.getNumVertices();
        std::vector<bool> visited(numVertices, false);
        std::queue<int> q;
        std::unordered_map<int, int> parent;

        q.push(start);
        visited[(size_t)start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // Check if the destination vertex is reached
            if (current == end) {
                // Reconstruct the shortest path
                std::string path = std::to_string(current);
                while (current != start) {
                    path = std::to_string(parent[current]) + " -> " + path;
                    current = parent[current];
                }
                return path;
            }

            // Traverse neighbors of the current vertex
            for (size_t neighbor = 0; neighbor < numVertices; ++neighbor) {
                if (g.getAdjacency(current, neighbor) && !(size_t)visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                }
            }
        }

        // No path found
        return "-1 (invalid path)";
    }

    // Check if the graph contains a cycle using DFS
    bool Algorithms::isContainsCycle(Graph g) {
        int numVertices = g.getNumVertices();
        std::vector<bool> visited(numVertices, false);
        std::vector<int> parent(numVertices, -1);
        std::vector<int> cycle;

        // Perform DFS from each vertex
        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i] && dfs(i, visited, parent, g, cycle)) {
                // Found a cycle
                return true;
            }
        }

        // No cycle found
        return false;
    }

    // Recursive function to perform DFS and detect cycles
    bool Algorithms::dfs(int v, std::vector<bool>& visited, std::vector<int>& parent, Graph& g, std::vector<int>& cycle) {
        visited[v] = true;

        // Traverse neighbors of the current vertex
        for (int u = 0; u < g.getNumVertices(); ++u) {
            if (g.getAdjacency(v, u) != 0) {
                if (!visited[u]) {
                    parent[u] = v;
                    if (dfs(u, visited, parent, g, cycle)) {
                        return true;
                    }
                } else if (u != parent[v]) {
                    // Found a back edge, indicating a cycle
                    cycle.push_back(u);
                    int current = v;
                    while (current != u) {
                        cycle.push_back(current);
                        current = parent[current];
                    }
                    cycle.push_back(u);
                    return true;
                }
            }
        }

        return false;
    }

    // Check if the graph is bipartite using BFS
    std::string Algorithms::isBipartite(ariel::Graph g) {
        int n = g.getNumVertices();
        std::vector<int> color(n, -1);  // -1: no color, 0: Group A, 1: Group B

        // Perform BFS from each vertex
        for (int start = 0; start < n; ++start) {
            if (color[start] == -1) {
                std::queue<int> q;
                q.push(start);
                color[start] = 0;  // Color the starting vertex with Group A

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    // Traverse neighbors of the current vertex
                    for (int v = 0; v < n; ++v) {
                        if (g.getAdjacency(u, v) != 0) {  // If there is an edge between u and v
                            if (color[v] == -1) {
                                // Color the neighboring vertex with the opposite color
                                color[v] = 1 - color[u];
                                q.push(v);
                            } else if (color[v] == color[u]) {
                                // If two neighboring vertices are colored with the same color, the graph is not bipartite
                                return "The graph is not bipartite.";
                            }
                        }
                    }
                }
            }
        }

        // Gather vertices into sets A and B
        std::vector<int> setA, setB;
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                setA.push_back(i);
            } else {
                setB.push_back(i);
            }
        }

        // Build the result string
        std::string result = "The graph is bipartite: A={";
        for (size_t i = 0; i < setA.size(); ++i) {
            result += std::to_string(setA[i]);
            if (i != setA.size() - 1) {
                result += ", ";
            }
        }
        result += "}, B={";
        for (size_t i = 0; i < setB.size(); ++i) {
            result += std::to_string(setB[i]);
            if (i != setB.size() - 1) {
                result += ", ";
            }
        }
        result += "}.";

        return result;
    }

    // Check for the presence of a negative cycle using Bellman-Ford algorithm
    bool Algorithms::negativeCycle(ariel::Graph g) {
        int n = g.getNumVertices();
        std::vector<int> dist(n, INT_MAX);
        std::vector<int> parent(n, -1);

        // Iterate over all vertices as potential sources
        for (int source = 0; source < n; source++) {
            // Reset distance and parent vectors
            std::fill(dist.begin(), dist.end(), INT_MAX);
            std::fill(parent.begin(), parent.end(), -1);

            dist[source] = 0;

            // Relax all edges n-1 times
            for (int i = 0; i < n - 1; i++) {
                for (int u = 0; u < n; u++) {
                    for (int v = 0; v < n; v++) {
                        int weight = g.getAdjacency(u, v);
                        if (weight != 0) { // Edge exists
                            if (dist[v] > dist[u] + weight) {
                                dist[v] = dist[u] + weight;
                                parent[v] = u;
                            }
                        }
                    }
                }
            }

            // Check for negative cycle
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    int weight = g.getAdjacency(u, v);
                    if (weight != 0) { // Edge exists
                        if (dist[v] > dist[u] + weight) {
                            // Negative cycle found, print path
                            std::vector<int> cycle;
                            int current = v;
                            while (true) {
                                cycle.push_back(current);
                                current = parent[current];
                                if (current == v || current == -1 || std::find(cycle.begin(), cycle.end(), current) != cycle.end()) {
                                    break; // Cycle completed or invalid vertex
                                }
                            }
                            if (current == v) {
                                std::cout << "Negative cycle found, path: ";
                                for (int i = cycle.size() - 1; i >= 0; --i) {
                                    std::cout << cycle[i];
                                    if (i > 0) {
                                        std::cout << "->";
                                    }
                                }
                                std::cout << std::endl;
                                return true;
                            }
                        }
                    }
                }
            }
        }

        std::cout << "No negative cycle found" << std::endl;
        return false;
    }




} // namespace ariel
