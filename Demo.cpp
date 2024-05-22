/*
 * ID: 211407424
 * abodezoabi2000@gmail.com
 */
#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    cout<<g1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    ariel::Graph g3 = g1 + g2; // Add the two graphs together.
    cout<<g3;           // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    g1 *= -2;        // Multiply the graph by -2.
    cout<<g1; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    g1 /= -2;
    cout<<g1;
    ariel::Graph g4 = g1 * g2; // Multiply the two graphs together.
    cout<<g4;           // Should print the multiplication of the matrices of g1 and g2: [0, 0, 2], [1, 0, 1], [1, 0, 0]

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph2); // Load the graph to the object.
    try
    {
        ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }

    ariel::Graph g11, g22, g33;

    // Load graphs with adjacency matrices
    vector<vector<int>> matrix1 = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    vector<vector<int>> matrix2 = {{0, 1, 1}, {1, 0, 2}, {1, 2, 0}};
    g11.loadGraph(matrix1);
    g22.loadGraph(matrix2);

    // Addition operator (+)
    g33 = g11 + g22;
    cout << "Addition of g11 and g22:\n" << g33 << endl;

    // Subtraction operator (-)
    g33 = g22 - g11;
    cout << "Subtraction of g11 from g22:\n" << g33 << endl;

    // Unary negation operator (-)
    g33 = -g11;
    cout << "Negation of g11:\n" << g33 << endl;

    // Unary plus operator (+)
    g33 = +g11;
    cout << "Unary plus of g11:\n" << g33 << endl;

    // Multiplication with a number operator (*)
    g33 = g11 * 2;
    cout << "Multiplication of g11 by 2:\n" << g33 << endl;

    // Multiplication with another graph operator (*)
    g33 = g11 * g22;
    cout << "Multiplication of g11 and g22:\n" << g33 << endl;

    // Division by a number operator (/)
    g33 = g22 /= 2;
    cout << "Division of g22 by 2:\n" << g33 << endl;

    // Equality operator (==)
    cout << "Are g11 and g22 equal? " << (g11 == g22) << endl;

    // Inequality operator (!=)
    cout << "Are g11 and g22 not equal? " << (g11 != g22) << endl;

    // Greater than operator (>)
    cout << "Is g11 greater than g22? " << (g11 > g22) << endl;

    // Greater than or equal to operator (>=)
    cout << "Is g11 greater than or equal to g22? " << (g11 >= g22) << endl;

    // Less than operator (<)
    cout << "Is g11 less than g22? " << (g11 < g22) << endl;

    // Less than or equal to operator (<=)
    cout << "Is g11 less than or equal to g22? " << (g11 <= g22) << endl;

    // Increment operators (++, pre-increment and post-increment)
    cout << "Incrementing g11 (pre-increment): " << (++g11) << endl;
    cout << "Incrementing g11 (post-increment): " << (g11++) << endl;

    // Decrement operators (--, pre-decrement and post-decrement)
    cout << "Decrementing g11 (pre-decrement): " << (--g11) << endl;
    cout << "Decrementing g11 (post-decrement): " << (g11--) << endl;



}