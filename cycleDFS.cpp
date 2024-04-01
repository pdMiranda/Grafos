#include <iostream>
#include <limits.h>
#include <list>
#include <vector>
using namespace std;

class Graph {
    vector<vector<int>> adj;
    int V; 
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
    Graph(int V);

    void addEdge(int v, int w);
    void showGraph();
    bool isCyclic();
};

Graph::Graph(int V) {
    this->V = V;
    adj = vector<vector<int>>(V, vector<int>(V, 0));
}

void Graph::addEdge(int v, int w) {
    adj[v][w] = 1;
    adj[w][v] = 1;
}

void Graph::showGraph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent) {
    visited[v] = true;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && adj[v][i]) {
            if (isCyclicUtil(i, visited, v))
                return true;
        }
        else if (i != parent && adj[v][i])
            return true;
    }
    return false;
}

bool Graph::isCyclic() {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }

    for (int u = 0; u < V; u++) {

        if (!visited[u]){
            if (isCyclicUtil(u, visited, -1)){
                return true;
            }
        }
    }

    return false;
}



int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    cout << "Grafo 1:\n";

    g1.showGraph();
    
    if (g1.isCyclic()) cout << "Contem ciclo" << endl;
    else cout << "Nao contem ciclo" << endl;

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    cout << "\nGrafo 2:\n";

    g2.showGraph();

    if(g2.isCyclic()) cout << "Contem ciclo" << endl;
    else cout << "Nao contem ciclo" << endl;

    return 0;
}