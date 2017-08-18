// Author: Jonathan Dinh
// Description: Simple implementation of DFS and BFS in C++

#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

struct Node {
    int d;
    bool visited;
    vector<int> adj;

    Node() {};
    Node(int d);
    void addEdge(int e);
};

Node::Node(int d) {
    this->d = d;
}

void Node::addEdge(int e) {
    this->adj.push_back(e);
}

struct Graph {
    int size;
    Node *nodes;  // number of vertices

    Graph(int V);
    void addEdge(int v, int e);
    void DFS(int v);
    void BFS(int v);
};

Graph::Graph(int V)
{
    size = V;
    nodes = new Node[V];
    for (int i = 0; i < V; i++) {
        nodes[i].d = i;
        nodes[i].visited = false;
    }
}

void Graph::addEdge(int v, int e)
{
    nodes[v].addEdge(e);        // v to e
    nodes[e].addEdge(v);       //  e to v
}

void Graph::BFS(int v)
{
    // array to keep track of which node was already visited
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++) {   // initialize to false
        visited[i] = false;
    }

    queue<int> q;
    q.push(nodes[v].d);
    visited[v] = true;

    // for each visited element, check its adjacent nodes and push it
    // onto the stack.
    // Run until stack is empty (no more nodes to print)
    while (!q.empty()) {
        int n = q.front();
        q.pop();

        cout << n << " ";
        vector <int> adj = nodes[n].adj;
        for (int i = 0; i < adj.size(); i++) {
            if (!visited[adj[i]]) {
                visited[adj[i]] = true;
                q.push(nodes[adj[i]].d);
            }
        }
    }
}


void Graph::DFS(int v)
{
    // array to keep track of which node was already visited
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++) {   // initialize to false
        visited[i] = false;
    }

    stack<int> s;
    s.push(nodes[v].d);
    visited[v] = true;

    // for each visited element, check its adjacent nodes and push it
    // onto the stack.
    // Run until stack is empty (no more nodes to print)
    while (!s.empty()) {
        int n = s.top();
        s.pop();
        cout << n << " ";

        vector <int> adj = nodes[n].adj;
        for (int i = 0; i < adj.size(); i++) {
            if (!visited[adj[i]]) {
                visited[adj[i]] = true;
                s.push(nodes[adj[i]].d);
            }
        }
    }
}

int main() {

    Graph g(5);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(4,1);

    cout << "DFS: ";
    g.DFS(1);
    cout << endl;
    cout << "BFS: ";
    g.BFS(1);

    return 0;
}
