#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = NULL;
    }
};

void addEdge(Node* adjList[], int u, int v) {
    Node* newNode = new Node(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void DFS(Node* adjList[], bool visited[], int u) {
    visited[u] = true;
    cout << u << " ";
    Node* ptr = adjList[u];
    while (ptr != NULL) {
        int v = ptr->val;
        if (!visited[v]) {
            DFS(adjList, visited, v);
        }
        ptr = ptr->next;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Node* adjList[V];
    bool visited[V] = {false};

    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
    }

    cout << "Enter the source and destination vertex for each edge:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
        addEdge(adjList, v, u);
    }

    cout << "DFS traversal starting from vertex 1: ";
    DFS(adjList, visited, 1);

    return 0;
}

