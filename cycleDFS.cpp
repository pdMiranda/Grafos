#include <iostream>
#include <limits.h>
#include <list>
#include <vector>
#include <chrono>

using namespace std;

class Graph {
    vector<vector<int>> adj;
    int V; 
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
    Graph(int V);

    void addEdge(int v, int w);
    void showGraph();
    int isCyclic();
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

int Graph::isCyclic() {
    int result=0;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }

    for (int u = 0; u < V; u++) {

        if (!visited[u]){
            if (isCyclicUtil(u, visited, -1)){
                result++ ;
            }
        }
    }

    return result;
}



int main()
{
    
    Graph g1(5);
    
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    
    g1.showGraph();
    cout << "\nGraph 1:\n";
    
    cout << "Cycles quantity " << g1.isCyclic() << "\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    cout << "\nGraph 2:\n";
    g2.showGraph();

    cout << "\nCycles quantity " << g2.isCyclic() << "\n";
  
    return 0;
}