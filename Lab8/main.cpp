#include <iostream>
using namespace std;

#include "graph.h"

int main() { 
    Graph g(8); 
    g.add_edge(0, 1); // A, B 
    g.add_edge(0, 3); // A, D
    g.add_edge(0, 6); // A, G
    g.add_edge(1, 4); // B, E
    g.add_edge(1, 5); // B, F
    g.add_edge(2, 5); // C, F
    g.add_edge(2, 7); // C, H
    g.add_edge(3, 5); // D, F
    g.add_edge(4, 6); // E, G
    
    cout << "Iterative Depth-first traversal Result of the Graph g:\n"; 
    g.dfs(); 

    cout << "\n\nBreadth-first traversal Result of the Graph g:\n"; 
    g.bfs(); 
}