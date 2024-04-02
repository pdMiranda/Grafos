#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <list>
#include <chrono>

using namespace std;

class Graph
{
public:
    Graph(int n) : adjList(n) {}

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    int size() const
    {
        return adjList.size();
    }

    const std::vector<int> &getAdjList(int node) const
    {
        return adjList[node];
    }

    void showGraph() const
    {
        for (int i = 0; i < adjList.size(); i++)
        {
            std::cout << "Vertice " << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++)
            {
                std::cout << adjList[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

private:
    std::vector<std::vector<int>> adjList;
};

int countCycles(Graph& graph) {
    int n = graph.size();
    int totalCycles = 0;

    for (int len = 3; len <= n; len++) {
        std::vector<bool> v(n);
        std::fill(v.end() - len, v.end(), true);

        do {
            std::vector<int> nodes;
            for (int i = 0; i < n; i++) {
                if (v[i]) {
                    nodes.push_back(i);
                }
            }

            do {
                bool isCycle = true;
                for (int i = 0; i < len; i++) {
                    int node = nodes[i];
                    int nextNode = nodes[(i + 1) % len];
                    if (std::find(graph.getAdjList(node).begin(), graph.getAdjList(node).end(), nextNode) == graph.getAdjList(node).end()) {
                        isCycle = false;
                        break;
                    }
                }
                if (isCycle) {
                    totalCycles++;
                }
            } while (std::next_permutation(nodes.begin(), nodes.end()));
        } while (std::next_permutation(v.begin(), v.end()));
    }

    return totalCycles;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    cout << "Graph 1:\n";
    g1.showGraph();

    cout << "Cycles quantity " << countCycles(g1) << "\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    cout << "\nGraph 2:\n";
    g2.showGraph();

    cout << "Cycles quantity " << countCycles(g2) << "\n";

    return 0;
}