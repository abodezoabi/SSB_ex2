/*
 * ID: 211407424
 * abodezoabi2000@gmail.com
 */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>


namespace ariel {

    class Algorithms {
    public:
        static bool isConnected( Graph g);
        static std::string shortestPath(Graph g, int start, int end);
        static bool   isContainsCycle(Graph g);
        static std::string isBipartite(Graph g);
        static bool negativeCycle(Graph g);
        //static bool DFS(Graph& g, int v, std::vector<bool>& visited, std::vector<int>& parent, std::vector<bool>& in_current_path, std::vector<int>& cycle);
    private:
        static bool dfs(int v, std::vector<bool>& visited, std::vector<int>& parent, Graph& g, std::vector<int>& cycle);
    };

} // namespace ariel

#endif // ALGORITHMS_HPP
