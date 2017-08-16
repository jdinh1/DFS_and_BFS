// Author: Jonathan Dinh
// Description: Simple implementation of DFS and BFS in C++

#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Graph {
    int V;  // number of vertices
    list <int> *adj;    // list of edges

public:
    Graph(int V);
    void addEdge(int v, int e);
    void DFS(int v);
    void BFS(int v);
    void DFSRun(int v, bool visited[]);     //helper function for DFS that uses recursion instead of a stack
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int e)
{
    adj[v].push_back(e);
}

void Graph::BFS(int v) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {   // initialize to false
        visited[i] = false;
    }

    queue<int> q;

    //visited[v] = true;
    q.push(v);

    while(!q.empty()) {
        // dequeue and print the value
        int c = q.front();
        q.pop();
        cout << c << " ";

        // keep adding onto the queue adjacent nodes that are not yet visited
        // and then mark them as visited
        list<int>::iterator i;
        for (i = adj[c].begin(); i != adj[c].end(); i++) {
            if(!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}


void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {   // initialize to false
        visited[i] = false;
    }

    //DFSRun(v, visited);   // uses recursion instead of a stack

    stack <int> s;
    s.push(v);

    while(!s.empty()) {     // run until stack is empty (no more nodes to print)
        // print current node on top of stack and remove it from the stack
        list <int>::iterator i;
        int current = s.top();
        s.pop();
        cout << current << " ";

        // visit any unvisited adjacent nodes and push them onto the stack
        for (i = adj[current].begin(); i != adj[current].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                s.push(*i);
            }
        }
    }
}

void Graph::DFSRun(int v, bool visited[]) {

    visited[v] = true;
    cout << v << " ";   // node is visited, print its value

    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); i++) {
        if (!visited[*i])
            DFSRun(*i, visited);
    }
}

int main() {

    Graph g(7);
    g.addEdge(0, 6);
    g.addEdge(2, 1);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 6);
    g.addEdge(1, 5);

    cout << "DFS: ";
    g.DFS(2);
    cout << endl;
    cout << "BFS: ";
    g.BFS(2);

    return 0;
}
