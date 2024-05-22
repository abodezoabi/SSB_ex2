/*
 * ID: 211407424
 * abodezoabi2000@gmail.com
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept> 
#include <iostream>

namespace ariel {

    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        int numVertices;
       // bool directed;
        bool weighted;

    public:
        bool directed;
        // Constructor
        Graph();

        std::string toString() const;

        // Load graph from adjacency matrix
        void loadGraph( std::vector<std::vector<int>> matrix);

        // Print graph information
        void printGraph() ;

        // Count edges in the graph
        int countEdges() const;

        // Get number of vertices in the graph
        int getNumVertices() ;

        // Get adjacency value between two vertices
        int getAdjacency(int row, int col)  ;
        int getNumVertices() const;
        int getAdjacency( const int row,const  int col) const   ;


        // Arithmetic operators
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator-() const;
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator+() const;
        /// TODOOOO ADDITIONAL FUNCS OPERATORS
        // boolean equality operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;

        // Increment and Decrement operators
        Graph& operator++();    // Prefix increment
        Graph operator++(int);  // Postfix increment
        Graph& operator--();    // Prefix decrement
        Graph operator--(int);  // Postfix decrement

        //  multiplying with number or graph
        Graph operator*(int number) const;
        Graph& operator*=(int number);
        Graph operator*(const Graph& other) const;
        Graph& operator*=(const Graph& other);
        Graph& operator/=(int number);// dividing by a number
        // Helper function to check if g1 contains g2
        bool isContain(const Graph& g1,const Graph& g2)const ;

        // Friend declaration for the output operator
        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
    };// graph class

    //  function definition for the output operator
    std::ostream& operator<<(std::ostream& os, const Graph& graph);

} // namespace ariel

#endif
