#include <iostream>
#include <climits>

using namespace std;

#define MAX_V 1000

int graph[MAX_V][MAX_V]; // adjacency matrix to store the graph
int dist[MAX_V]; // distance from source to each vertex
bool visited[MAX_V]; // whether a vertex is visited or not

int prim(int V) {
    int mst = 0; // minimum spanning tree weight
    fill(dist, dist + V, INT_MAX); // initialize all distances to infinity
    fill(visited, visited + V, false); // initialize all vertices as unvisited
    dist[0] = 0; // set distance of source vertex to 0
    for(int i=0; i<V; i++) {
        int u = -1; // vertex with minimum distance
        for(int j=0; j<V; j++) {
            if(!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }
        visited[u] = true;
        mst += dist[u];
        for(int v=0; v<V; v++) {
            if(graph[u][v] != 0 && !visited[v] && graph[u][v] < dist[v])
                dist[v] = graph[u][v];
        }
    }
    return mst;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    cout << "Enter the source vertex, destination vertex and weight of each edge: " << endl;
    for(int i=0; i<E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // since it's an undirected graph
    }
    cout << "The minimum spanning tree weight is: " << prim(V) << endl;
    return 0;
}

