## Implementing And Testing Operators on Graphs 
ID: 211407424
Email: abodezoabi2000@gmail.com 

### Introduction

This assignment involves implementing a graph class in C++ with a variety of features and functionalities. The graph is represented using an adjacency matrix, and the class supports both directed and undirected graphs as well as weighted and unweighted graphs. The graph class includes various operators for graph manipulation and comparison, making it a comprehensive tool for graph-related operations.

### Contents

- **Graph.hpp**: Header file containing the class definition and member function declarations.
- **Graph.cpp**: Implementation file containing the definitions of the member functions.
- **Algorithms.hpp**: Header file containing algorithm implementations from the first assignment.
- **Algorithms.cpp**: Implementation file containing the definitions of the algorithms from the first assignment.
- **demo.cpp**: A demonstration file showing how to use the Graph class, acting as a sort of main file.
- **test.cpp**: A test file testing and verifying the correctness of the Graph class implementation.
- **Makefile**: A makefile to compile and run the demo and test files.

### Operators Defined:

#### Arithmetic Operators

- **Addition (`+`, `+=`)**: Combine the edges of two graphs.
- **Subtraction (`-`, `-=`)**: Subtract the edges of one graph from another.
- **Unary Negation (`-`)**: Negate all the edges in the graph.
- **Multiplication (`*`, `*=`)**: Multiply the edges of the graph by an integer or perform graph multiplication.

#### Comparison Operators

- **Equality (`==`)**: Check if two graphs are equal.
- **Inequality (`!=`)**: Check if two graphs are not equal.
- **Greater than (`>`, `>=`)**: Compare two graphs based on the number of vertices and edges.
- **Less than (`<`, `<=`)**: Compare two graphs based on the number of vertices and edges.

#### Increment and Decrement Operators

- **Increment (`++`, `++(int)`)**: Increment all the edges in the graph.
- **Decrement (`--`, `--(int)`)**: Decrement all the edges in the graph.

#### Miscellaneous Operators

- **Division (`/=`)**: Divide all the edges in the graph by an integer.
- **Output Stream (`<<`)**: Output the graph in a readable format.

### How to Compile and Run

To compile and run the demonstration and test files, you can use the provided `Makefile`. Below are the commands to compile, run, and clean the files:

#### Compile and Run the Demonstration

1. **Compile and Run**:
   ```sh
   make
   
2. **Compile and Run the Tests**
 Compile the Tests:
```sh
make test
Run the Tests:
```sh
./test
Clean the Compiled Files
To remove all compiled files and clean the directory, use the following command:

```sh
Copy code
make clean


This assignment demonstrates a comprehensive implementation of a graph class in C++, showcasing various operator overloads and functionalities for graph manipulation and comparison. The provided Makefile simplifies the process of compiling and running the demonstration and tests, ensuring an efficient workflow.
#After testing the Algorithms we found that te operators we defined had no influence no any of the Algorithms we implemented in the first assignment.
