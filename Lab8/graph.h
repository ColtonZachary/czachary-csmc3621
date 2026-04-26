#ifndef GRAPH_H
#define GRAPH_H

#include <iostream> 
#include <list> 
#include <stack>
#include <queue>
#include <vector>

using namespace std; 

class Graph { 
    int numOfVertices;
    list<int> *adjList;

public: 
    Graph(int n) {
        numOfVertices = n; 
        adjList = new list<int>[numOfVertices]; 
    }

    void add_edge(int v, int u) { // This method we assume the graph is non-directional, so we add the edge to both lists
                                 // (depends on your implemeentation of the adjacency list, you can use push_front() or push_back())
        adjList[v].push_front(u); // Add vertex v to neighbor u’s list. 
        adjList[u].push_front(v); // Add neighbor u to vertex v’s list. 
    }

    void print_letter(int v);    // This method is to print out the letter instead of index number, 0 => A, 1 => B, ... 7 => H

    void dfs();
    void dfs_util(int v, vector<bool> &visited);

    void bfs(); 

}; 

void Graph::print_letter(int v){
    char ch = v + 65;
    cout << ch << " ";
}
   
// DFS 
void Graph::dfs() { 
    // 1. Initialize all vertices to unvisited
    vector<bool> visited(numOfVertices, false);

    // 2. For each vertex v in the vertex set V
    // (hint: you can use a for loop with numOfVertices to go through each vertex in the graph)

    //     If the vertex is not visited (use the index i of the for loop to check the bool vector visited whether it is false)
    //     call dfs_util() to go deeper in that vertex 
    //     to call dfs_util(), you will pass two parameters, the index i and the bool vector visited
    for (int i = 0; i < numOfVertices; i++) { // For each vertex v in the vertex set V
        if (visited[i] == false) // If the vertex is not visited (use the index i of the for loop to check the bool vector visited whether it is false)
            dfs_util(i, visited); // call dfs_util() to go deeper in that vertex
    }

}

void Graph::dfs_util(int v, vector<bool> &visited) { 
    
    // 1. Declare a stack named s (use the STL stack of int type)
    // 2. Push the vertex v to the top of the stack

    // 3. While the stack s is not empty (while loop iteration)
    //        in each iteration, get the top item of the stack s as the vertex v (hint: use top() in STL stack)
    //        pop the top item in the stack

    //        check if the vertex v is not visited, if it is not visited
    //            mark the vertex v as visited in the bool vector visited
    //            print out the result (use print_letter() to print out the vertex v, it will print out the capital letter instead of the index number)

    //        use a for loop to go through all the adjacent vertices of the vertex v
    //        (as AdjList is an array of STL list, you need to use adjList[v] to access the list of that vertex v)
    //        (you will also need to use iterator in the list, we did it in lab6)
    //        (you can use auto keyword for auto-define the type of the iterator it, first you will start with adjList[v].begin(), 
    //         as long as it has not reached adjList[v].end(), the loop will continue, it will increase one step in every iteration)

    //            check if the vertex that the iterator it is pointing to is not visited (as iterator it is also a pointer, 
    //            to retrieve the vertex that it is pointing to, we can use dereference operator, i.e. check whether visited[*it] is false)
    //                push the vertex to the stack if it is not yet visited so that we can continue to go deeper
    stack<int> s; // Declare a stack named s (use the STL stack of int type)
    s.push(v); // Push the vertex v to the top of the stack

    while (!s.empty()) { 
        v = s.top(); // in each iteration, get the top item of the stack s as the vertex v (hint: use top() in STL stack)
        s.pop(); // pop the top item in the stack

        if (visited[v] == false) { // check if the vertex v is not visited, if it is not visited
            visited[v] = true; // mark the vertex v as visited in the bool vector visited
            print_letter(v); // print out the result (use print_letter() to print out the vertex v, it will print out the capital letter instead of the index number)
        }

        for (auto it = adjList[v].begin(); it != adjList[v].end(); it++) { // use a for loop to go through all the adjacent vertices of the vertex v
            if (visited[*it] == false) // check if the vertex that the iterator it is pointing to is not visited (as iterator it is also a pointer,
                s.push(*it); // push the vertex to the stack if it is not yet visited so that we can continue to go deeper
        }
    }
}


// BFS
void Graph::bfs() {
    // 1. Initialize all vertices to unvisited
    // 2. Declare a queue named q (use the STL queue of int type)

    // 3. For each vertex v in the vertex set V
    // (hint: you can use a for loop with numOfVertices to go through each vertex in the graph)

    //     If the vertex is not visited (use the index i of the for loop to check the bool vector visited whether it is false)
    //         enqueue the vertex to the queue (in STL queue, the enqueue function is also named push(), which will push the item to the back of the queue)
    //         mark the vertex as visited in the bool vector visited
    //         print out the result (use print_letter() to print out the vertex, it will print out the capital letter instead of the index number)


    //     While the queue q is not empty (while loop iteration)
    //        in each iteration, get the first item of the queue q as the vertex v (hint: use front() in STL front)
    //        dequeue the first item in the stack (in STL queue, the dequeue function is also named pop(), which will remove the first item in the queue)

    //        use a for loop to go through all the adjacent vertices of the vertex v
    //        (as AdjList is an array of STL list, you need to use adjList[v] to access the list of that vertex v)
    //        (you will also need to use iterator in the list, we did it in lab6)
    //        (you can use auto keyword for auto-define the type of the iterator it, first you will start with adjList[v].begin(), 
    //         as long as it has not reached adjList[v].end(), the loop will continue, it will increase one step in every iteration)

    //            check if the vertex that the iterator it is pointing to is not visited (as iterator it is also a pointer, 
    //            to retrieve the vertex that it is pointing to, we can use dereference operator, i.e. check whether visited[*it] is false)
    //                enqueue the vertex to the queue
    //                mark the vertex as visited in the bool vector visited
    //                print out the result (use print_letter() to print out the vertex, it will print out the capital letter instead of the index number)
    vector<bool> visited(numOfVertices, false); // Initialize all vertices to unvisited
    queue<int> q; // Declare a queue named q (use the STL queue of int type)

    for (int i = 0; i < numOfVertices; i++) { // For each vertex v in the vertex set V
        if (visited[i] == false) { // If the vertex is not visited (use the index i of the for loop to check the bool vector visited whether it is false)
            q.push(i); // enqueue the vertex to the queue (in STL queue, the enqueue function is also named push(), which will push the item to the back of the queue)
            visited[i] = true; // mark the vertex as visited in the bool vector visited
            print_letter(i); // print out the result (use print_letter() to print out the vertex, it will print out the capital letter instead of the index number)
        }

        while (!q.empty()) { // While the queue q is not empty (while loop iteration)
            int v = q.front(); // in each iteration, get the first item of the queue q as the vertex v (hint: use front() in STL front)
            q.pop(); // dequeue the first item in the stack (in STL queue, the dequeue function is also named pop(), which will remove the first item in the queue)

            for (auto it = adjList[v].begin(); it != adjList[v].end(); it++) { // use a for loop to go through all the adjacent vertices of the vertex v
                if (visited[*it] == false) { // check if the vertex that the iterator it is pointing to is not visited (as iterator it is also a pointer,
                    q.push(*it); // enqueue the vertex to the queue
                    visited[*it] = true; // mark the vertex as visited in the bool vector visited
                    print_letter(*it); // print out the result (use print_letter() to print out the vertex, it will print out the capital letter instead of the index number)
                }
            }
        }
    }
}



#endif