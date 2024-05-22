/*
 * ID: 211407424
 * abodezoabi2000@gmail.com
 */

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;

    vector<vector<int>> expectedGraph = {
            {0, 2, 1},
            {2, 0, 3},
            {1, 3, 0}};
    ariel::Graph g31;
    g31.loadGraph(expectedGraph);
    CHECK((g3==g31)== true);

}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;

    vector<vector<int>> expectedGraph = {
            {0, 0, 2},
            {1, 0, 1},
            {1, 0, 0}
    };
    ariel::Graph g44;
    g44.loadGraph(expectedGraph);

//    CHECK(g4>=g44);
//    CHECK(g4<=g44);
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1, 1},
            {1, 0, 2, 1},
            {1, 2, 0, 1},
            {1, 2, 3, 4}};
    (g2.loadGraph(weightedGraph));
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("Test adding the Graph with itself")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g3 = g1 + g1;

    vector<vector<int>> expectedGraph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    ariel::Graph g31;
    g31.loadGraph(expectedGraph);
    CHECK((g3 == g31) == true);
}

TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 - g2;

    vector<vector<int>> expectedGraph = {
            {-8, -6, -4},
            {-2, 0, 2},
            {4, 6, 8}};
    ariel::Graph g31;
    g31.loadGraph(expectedGraph);
    CHECK((g3 == g31) == true);
}

TEST_CASE("Test graph negation")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, -2, 3},
            {-4, 5, -6},
            {7, -8, 9}};
    g1.loadGraph(graph);
    ariel::Graph g2 = -g1;

    vector<vector<int>> expectedGraph = {
            {-1, 2, -3},
            {4, -5, 6},
            {-7, 8, -9}};
    ariel::Graph g21;
    g21.loadGraph(expectedGraph);
    CHECK((g2 == g21) == true);
}

TEST_CASE("Test graph incrementing")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    g1.loadGraph(graph);
    ariel::Graph g2 = ++g1;

    vector<vector<int>> expectedGraph = {
            {2, 3, 4},
            {5, 6, 7},
            {8, 9, 10}};
    ariel::Graph g21;
    g21.loadGraph(expectedGraph);
    CHECK((g2 == g21) == true);
}

TEST_CASE("Test graph decrementing")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    g1.loadGraph(graph);
    ariel::Graph g2 = --g1;

    vector<vector<int>> expectedGraph = {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8}};
    ariel::Graph g21;
    g21.loadGraph(expectedGraph);
    CHECK((g2 == g21) == true);
}

TEST_CASE("Test graph adding")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2}};
    g2.loadGraph(graph2);
    g1 += g2;

    vector<vector<int>> expectedGraph = {
            {3, 3, 3},
            {3, 3, 3},
            {3, 3, 3}};
    ariel::Graph g21;
    g21.loadGraph(expectedGraph);
    CHECK((g1 == g21) == true);
}

TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {3, 3, 3},
            {3, 3, 3},
            {3, 3, 3}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2}};
    g2.loadGraph(graph2);
    g1 -= g2;

    vector<vector<int>> expectedGraph = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};
    ariel::Graph g21;
    g21.loadGraph(expectedGraph);
    CHECK((g1 == g21) == true);
}

TEST_CASE("Test graph multiplication by integer")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 * 2;

    vector<vector<int>> expectedGraph = {
            {2, 4, 6},
            {8, 10, 12},
            {14, 16, 18}};
    ariel::Graph g21;
    g21.loadGraph(expectedGraph);
    CHECK((g2 == g21) == true);
}

TEST_CASE("Test graph multiplication assignment by integer")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    g1.loadGraph(graph);
    g1 *= 2;

    vector<vector<int>> expectedGraph = {
            {2, 4, 6},
            {8, 10, 12},
            {14, 16, 18}};
    ariel::Graph g21;
    g21.loadGraph(expectedGraph);
    CHECK((g1 == g21) == true);
}

TEST_CASE("Test graph division assignment by an integer")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {2, 4, 6},
            {8, 10, 12},
            {14, 16, 18}};
    g1.loadGraph(graph);
    g1 /= 2;

    vector<vector<int>> expectedGraph = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    ariel::Graph g21;
    g21.loadGraph(expectedGraph);
    CHECK((g1 == g21) == true);
}

TEST_CASE("Test graph equality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    g2.loadGraph(graph);
    CHECK(g1 == g2);
}

TEST_CASE("Test graph inequality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}};
    g2.loadGraph(graph2);
    CHECK(g1 != g2);
}

TEST_CASE("Test graph greater than")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};
    g2.loadGraph(graph2);
    CHECK(g1 > g2);
}

TEST_CASE("Test graph less than")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2}};
    g2.loadGraph(graph2);
    CHECK(g1 < g2);
}

TEST_CASE("Test graph greater than or equal")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    g2.loadGraph(graph);
    CHECK(g1 >= g2);
}

TEST_CASE("Test graph less than or equal")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    g2.loadGraph(graph);
    CHECK(g1 <= g2);
}

TEST_CASE("Test graph equality with different dimensions")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {1, 1},
            {1, 1}};
    g2.loadGraph(graph2);
    CHECK(g1 != g2);
}

TEST_CASE("Test graph equality with same dimensions but different weights")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 2}};
    g2.loadGraph(graph2);
    CHECK(g1 != g2);
}


TEST_CASE("Test inequality with different weights")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 2}};
    g2.loadGraph(graph2);
    CHECK(g1 > g2);
}

TEST_CASE("Testing inequality with different weights")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 2}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2}};
    g2.loadGraph(graph2);
    CHECK(g1 < g2);
}
