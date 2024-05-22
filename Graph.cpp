/*
 * ID: 211407424
 * abodezoabi2000@gmail.com
 */

#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <sstream>

namespace ariel {

    Graph::Graph() : numVertices(0), directed(false), weighted(false) {}

    void Graph::loadGraph(std::vector <std::vector<int>> matrix) { // Load graph from adjacency matrix
        size_t n = matrix.size();
        for (size_t i = 0; i < n; ++i) { // Check if each row has the same size as the matrix
            if (matrix[i].size() != n) {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix."); // Throw error if not square
            }
        }
        if (matrix.size() != matrix[0].size()) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        numVertices = static_cast<int>(matrix.size());
        adjacencyMatrix = matrix;
        directed = false;
        weighted = false;

        // Determine if the graph is directed based on the matrix
        for (std::vector < std::vector < int >> ::size_type i = 0; i < matrix.size(); i++) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); j++) {
                if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) { // Check if matrix is symmetric
                    directed = true; // Set as directed if not symmetric
                    break;
                }
            }
            if (directed) break;
        }

        // Determine if the graph is weighted based on the matrix
        for (const auto &row: matrix) {
            for (int val: row) {
                if (val != row[0] && val != 0) { // Check for different weights
                    weighted = true; // Set as weighted if different weights found
                }
            }
        }
    }

    void Graph::printGraph() {
        std::cout << "Graph with " << numVertices << " vertices and " << countEdges() << " edges." << std::endl;
    }

    std::string Graph::toString() const {
        std::stringstream ss;
        for (const auto& row : adjacencyMatrix) {
            ss << "[";
            for (size_t i = 0; i < row.size(); ++i) {
                ss << row[i];
                if (i < row.size() - 1) {
                    ss << ", ";
                }
            }
            ss << "]\n";
        }
        return ss.str();
    }

    int Graph::countEdges() const { // Count the number of edges in the graph
        int edges = 0;
        for (const auto &row: adjacencyMatrix) {
            for (int val: row) {
                if (val > 0) {
                    edges++;
                }
            }
        }
        return edges;
    }

    int Graph::getNumVertices() {
        return numVertices;
    }
    int Graph::getNumVertices() const {
        return numVertices;
    }

    int Graph::getAdjacency(int row, int col) {
        if (row < 0 || col < 0 || static_cast<size_t>(row) >= adjacencyMatrix.size() ||
            static_cast<size_t>(col) >= adjacencyMatrix[0].size()) {
            return 0; // Return 0 if out of bounds
        }
        return adjacencyMatrix[static_cast<size_t>(row)][static_cast<size_t>(col)];
    }

    int Graph::getAdjacency(const int row, const int col) const {
        if (row < 0 || col < 0 || static_cast<size_t>(row) >= adjacencyMatrix.size() ||
            static_cast<size_t>(col) >= adjacencyMatrix[0].size()) {
            return 0;
        }
        return adjacencyMatrix[static_cast<size_t>(row)][static_cast<size_t>(col)];
    }

    // Overload the output operator to print the graph
    std::ostream &operator<<(std::ostream &os, const Graph &graph) {
        os << graph.toString();
        return os;
    }

    // Overload the + operator to add two graphs
    Graph Graph::operator+(const Graph &other) const {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Invalid operation: Graphs have different numbers of vertices.");
        }

        std::vector <std::vector<int>> result_matrix(numVertices, std::vector<int>(numVertices, 0)); // Initialize the result matrix

        for (int i = 0; i < numVertices; ++i) { // Iterate over each cell
            for (int j = 0; j < numVertices; ++j) {
                result_matrix[i][j] = adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j]; // Add corresponding cells
            }
        }

        Graph result_graph;
        result_graph.loadGraph(result_matrix);
        return result_graph;
    }

    // Overload the += operator to add another graph to this graph
    Graph &Graph::operator+=(const Graph &other) {
        if (numVertices != other.numVertices) { // Check if the graphs have the same number of vertices
            throw std::invalid_argument("Invalid operation: Graphs have different numbers of vertices.");
        }

        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
            }
        }

        return *this;
    }

    // Overload the unary + operator to return a copy of the graph
    Graph Graph::operator+() const {
        Graph copy(*this); // Create a copy of the graph
        return copy;
    }

    // Overload the - operator to subtract one graph from another
    Graph Graph::operator-(const Graph &other) const {
        if (numVertices != other.numVertices) { // Check if the graphs have the same number of vertices
            throw std::invalid_argument("Invalid operation: Graphs have different numbers of vertices."); // Throw error if not
        }

        std::vector <std::vector<int>> result_matrix(numVertices, std::vector<int>(numVertices, 0)); // Initialize the result matrix

        for (int i = 0; i < numVertices; ++i) { // Iterate over vertices
            for (int j = 0; j < numVertices; ++j) {
                result_matrix[i][j] = adjacencyMatrix[i][j] - other.adjacencyMatrix[i][j];
            }
        }

        Graph result_graph; // Create a new graph for the result
        result_graph.loadGraph(result_matrix); // Load the result matrix into the new graph
        return result_graph;
    }

    // Overload the -= operator to subtract another graph from this graph
    Graph &Graph::operator-=(const Graph &other) {
        if (numVertices != other.numVertices) { // Check if the graphs have the same number of vertices
            throw std::invalid_argument("Invalid operation: Graphs have different numbers of vertices."); // Throw error if not
        }

        for (int row = 0; row < numVertices; ++row) {
            for (int col = 0; col < numVertices; ++col) {
                adjacencyMatrix[row][col] -= other.adjacencyMatrix[row][col];
            }
        }

        return *this;
    }

    // Overload the unary - operator to return a negated graph
    Graph Graph::operator-() const {
        std::vector <std::vector<int>> negated_matrix(numVertices, std::vector<int>(numVertices, 0)); // Initialize the negated matrix

        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                negated_matrix[i][j] = -adjacencyMatrix[i][j]; // Negate the cell value
            }
        }

        Graph negated_graph; // Create a new graph for the negated matrix
        negated_graph.loadGraph(negated_matrix); // Load the negated matrix into the new graph
        return negated_graph; // Return the new graph
    }

    // Overload the == operator to compare two graphs for equality
    bool Graph::operator==(const Graph &other) const {
        if (numVertices != other.numVertices) return false; // Check if the number of vertices is the same

        for (int i = 0; i < numVertices; ++i) { // Iterate over each cell
            for (int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] != other.adjacencyMatrix[i][j]) { // Check if corresponding cells are equal
                    return false;
                }
            }
        }

        return true; // Return true if all cells are equal
    }

    // Overload the != operator to compare two graphs for inequality
    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other); // Return the negation of the equality operator
    }

    // Helper function to check if g1 is a proper subgraph of g2
    bool Graph::isContain(const Graph& g1, const Graph& g2) const {
        if (g1.getNumVertices() >= g2.getNumVertices()) return false; // Check if g1 has more vertices than g2

        for (size_t i = 0; i < g1.getNumVertices(); ++i) { // Iterate over each verices in g1
            for (size_t j = 0; j < g1.getNumVertices(); ++j) {
                if (g1.getAdjacency(i, j) && !g2.getAdjacency(i, j)) { // Check if g1 has an edge not in g2
                    return false;
                }
            }
        }
        return true;
    }

    // Overload the > operator to compare two graphs
    bool Graph::operator>(const Graph& other) const {
        // Check if the number of vertices in the left-hand side graph is greater than the number of vertices in the right-hand side graph
        if (this->numVertices > other.numVertices) {
            // If g1 has more vertices than g2, it cannot be less than g2
            return true;
        }

        // Check if g1 is contained in g2
        bool result = isContain(*this, other);

        // If g1 is not contained in g2, compare based on the number of edges
        if (!result) {
            // Compare the number of edges
            int edgesThis = this->countEdges();
            int edgesOther = other.countEdges();
            result = (edgesThis > edgesOther); // Compare edge counts
        }

        // Check if the adjacency matrices of the two graphs are lexicographically greater than the other
        return adjacencyMatrix > other.adjacencyMatrix;
    }

    // Overload the >= operator to compare two graphs
    bool Graph::operator>=(const Graph& other) const {
        return (*this > other) || (*this == other);
    }

    // Overload the < operator to compare two graphs
    bool Graph::operator<(const Graph& other) const {
        // Check if the number of vertices in the left-hand side graph is greater than the number of vertices in the right-hand side graph
        if (this->numVertices > other.numVertices) {
            // If g1 has more vertices than g2, it cannot be less than g2
            return false;
        }

        // Check if g1 is contained in g2
        bool result = isContain(*this, other);

        // If g1 is not contained in g2, compare based on the number of edges
        if (!result) {
            // Compare the number of edges
            int edgesThis = this->countEdges();
            int edgesOther = other.countEdges();
            result = (edgesThis < edgesOther); // Compare edge counts
        }

        // Check if the adjacency matrices of the two graphs are lexicographically less than the other
        return adjacencyMatrix < other.adjacencyMatrix;
    }

    // Overload the <= operator to compare two graphs
    bool Graph::operator<=(const Graph& other) const {
        return (*this < other) || (*this == other);
    }

    // Increment and Decrement operators
    Graph& Graph::operator++() { // Prefix increment
        for (auto& row : adjacencyMatrix) { // Iterate over each row
            for (auto& val : row) { // Iterate over each value in the row
                val += 1; // Incease each value by 1
            }
        }
        return *this;
    }

    Graph Graph::operator++(int) { // Postfix increment
        Graph temp = *this; // Create a temporary copy of this graph
        ++(*this); // Use prefix increment
        return temp;
    }

    Graph& Graph::operator--() { // Prefix decrement
        for (auto& row : adjacencyMatrix) { // Iterate over each row
            for (auto& val : row) { // Iterate over each value in the row
                val -= 1; // Decrement each value
            }
        }
        return *this;
    }

    Graph Graph::operator--(int) { // Postfix decrement
        Graph temp = *this; // Create a temporary copy of this graph
        --(*this); // Use prefix decrement
        return temp;
    }

    // Integer multiplication
    Graph Graph::operator*(int number) const { // Overload the * operator for integer multiplication
        Graph result(*this); // Create a copy of this graph
        for (auto& row : result.adjacencyMatrix) { // Iterate over each row in the result graph
            for (auto& val : row) { // Iterate over each value in the row
                val *= number; // Multiply each value by the given number
            }
        }
        return result;
    }

    Graph& Graph::operator*=(int number) { // Overload the *= operator for integer multiplication
        for (auto& row : adjacencyMatrix) { // Iterate over each row
            for (auto& val : row) { // Iterate over each value in the row
                val *= number; // Multiply each value by the given number
            }
        }
        return *this;
    }

    // Graph multiplication
    Graph Graph::operator*(const Graph& other) const { // Overload the * operator for graph multiplication
        // Check if the number of vertices in both graphs are the same
        if (adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
            throw std::invalid_argument("Graphs must be the same size to multiply them."); // Throw error if not
        }

        // Initialize the resulting graph
        Graph result;
        size_t n = adjacencyMatrix.size(); // Get the size of the matrix
        result.adjacencyMatrix.resize(n, std::vector<int>(n, 0)); // Resize the result matrix

        // Perform matrix multiplication
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                for (size_t k = 0; k < n; ++k) {
                    result.adjacencyMatrix[i][j] += adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j]; // Multiply and add
                }

                if (i == j) {
                    result.adjacencyMatrix[i][j] = 0; // Set diagonal elements to 0
                }
            }
        }

        return result;
    }

    Graph& Graph::operator*=(const Graph& other) { // Overload the *= operator for graph multiplication
        if (numVertices != other.numVertices) { // Check if the number of vertices is same
            throw std::invalid_argument("Graphs must be of the same size for multiplication"); // Throw error if not
        }
        Graph result = *this * other; // Multiply the graphs
        *this = result; // Assign the result to this graph
        return *this; // Return this graph
    }

    // Overload the /= operator for division by an integer
    Graph& Graph::operator/=(int num) {
        if (num == 0) { throw std::invalid_argument("Cannot divide by zero"); } // Check for division by zero
        for (auto& row : adjacencyMatrix) {
            for (int& val : row) {
                val /= num; // Divide each value by the given scalar
            }
        }
        return *this;
    }

} // NAMESPACE ARIEL
