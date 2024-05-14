#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int parent[], int i) {
    if(parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if(rootX == rootY)
        return;
    if(rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if(rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

vector<Edge> kruskalMST(Edge edges[], int n, int m) {
    vector<Edge> result;
    int parent[n];
    int rank[n];
    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    sort(edges, edges+m, compare);
    int i = 0, j = 0;
    while(i < n-1 && j < m) {
        Edge e = edges[j++];
        int x = find(parent, e.u);
        int y = find(parent, e.v);
        if(x != y) {
            result.push_back(e);
            Union(parent, rank, x, y);
            i++;
        }
    }
    return result;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges of the graph: ";
    cin >> n >> m;
    Edge edges[m];
    cout << "Enter the source, destination, and weight of each edge: " << endl;
    for(int i=0; i<m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    vector<Edge> MST = kruskalMST(edges, n, m);
    cout << "Minimum Spanning Tree:" << endl;
    for(auto e : MST) {
        cout << e.u << " " << e.v << " " << e.w << endl;
    }
    return 0;
}

