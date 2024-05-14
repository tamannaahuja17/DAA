#include <iostream>
#include <queue>

using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Graph class
class Graph {
private:
    int V;          // number of vertices
    Node** adjList;  // adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adjList = new Node*[V];
        for (int i = 0; i < V; i++) {
            adjList[i] = NULL;
        }
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        Node* newNode = new Node;
        newNode->data = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }

    // Breadth-First Search traversal of the graph
    void BFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            Node* temp = adjList[curr];
            while (temp != NULL) {
                int adj = temp->data;
                if (!visited[adj]) {
                    visited[adj] = true;
                    q.push(adj);
                }
                temp = temp->next;
            }
        }
    }
};

// Main function
int main() {
    int V, E, u, v, start;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "Enter the starting vertex for BFS traversal: ";
    cin >> start;
    cout << "BFS traversal: ";
    g.BFS(start);
    cout << endl;
    return 0;
}

