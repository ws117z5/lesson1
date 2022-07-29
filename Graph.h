#include <iostream>
#include <map>
#include <vector>
#include "MinHeap.h"

namespace gr {

//Disjoint Set Union
class DSU {
    int* parent;
    int* rank;
  
public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
  
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
  
    int find(int i) {
        if (parent[i] == -1)
            return i;
  
        return parent[i] = find(parent[i]);
    }
    
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
  
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
protected:
    map<int, bool> visited;
    map<int, std::vector<int> > adj;
public:
    void addEdge(int a, int b) {
        this->adj[a].push_back(b);
        this->visited[a] = false;
    }
 
    void DFS(int v) {
        this->visited[v] = true;
        std::cout << v << " ";
    
        std::vector<int>::iterator i;
        for (i = this->adj[v].begin(); i != this->adj[v].end(); ++i) {
            if (!this->visited[*i]) {
                DFS(*i);
            }
        }
    }

    std::vector<vector<int> > convertToMatrix()
    {
        int V = this->visited.size();
        // Initialize a matrix
        std::vector<std::vector<int>> matrix(V,vector<int>(V, 0));
    
        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) {
                matrix[i][j] = 1;
            }
        }
        return matrix;
    }

    void printMatrix()
    {

        std::vector<std::vector<int>> matrix = convertToMatrix();

        int V = this->visited.size();
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                std::cout << matrix[i][j] << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

class WeightedGraph : private Graph {
protected:
    using Graph::Graph;
    using Graph::visited;
    map<int, std::vector<std::pair<int, int>> > adj;

public:
    void addEdge(int a, int b, int w) {
        this->adj[a].push_back(std::pair(b, w));
        this->visited[a] = false;
    }
 
    void DFS(int v) {
        this->visited[v] = true;
        std::cout << v << " ";
    
        vector<std::pair<int, int>>::iterator i;
        for (i = this->adj[v].begin(); i != this->adj[v].end(); ++i) {
            if (!this->visited[(*i).first]) {
                //std::cout << "-" << (*i).second << "-> ";
                DFS((*i).first);
            }
        }
    }

    std::vector<vector<int> > convertToMatrix()
    {
        int V = this->visited.size();
        // Initialize a matrix
        std::vector<std::vector<int>> matrix(V,vector<int>(V, 0));
    
        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) {
                matrix[i][j.first] = j.second;
            }
        }
        return matrix;
    }

    void printMatrix()
    {

        std::vector<std::vector<int>> matrix = convertToMatrix();

        int V = this->visited.size();
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                std::cout << matrix[i][j] << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void kruskals_mst()
    {
        int V = this->visited.size();

        //1. fill edge array
        vector<vector<int>> edges;
        for (int i = 0; i < this->adj.size(); i++) {
            for(auto edge : this->adj[i]) {
                edges.push_back(std::vector<int>{edge.second, i, edge.first});
            }
            
        }

        // 2. Sort all edges
        std::sort(edges.begin(), edges.end(), [](std::vector<int> a, std::vector<int> b) {
            return a[0] < b[0];
        });
  
        // 3. Initialize the DSU
        DSU s(V);
        int ans = 0;
        std::cout << "MST: " << std::endl;
        for (auto edge : edges) {
            int w = edge[0];
            int a = edge[1];
            int b = edge[2];
  
            // take that edge in MST if it does form a cycle
            if (s.find(a) != s.find(b)) {
                s.unite(a, b);
                ans += w;
                cout << a << " -- " << b << " == " << w << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};

//Graphs 
// Weighted - Weightless
// Single / Bi Directional
// Adjacency Matrix / Adjacency List
// \ 0 1 2 3 4 5 6 7 8 9 10 11 12
// 0 1 1 1 1 1 0 0 1 1 1  0  0  0
// 1 0 1 0 0 0 0 1 0 1 0  1 1 1
// 2 0 0 0 0 1 0 0 0 0 0  0 0 0
// 3 0 1 1 1 1 1 1 1 1 1  1 1 1
 
 // Adjecency matrix 
 // \ 0 1 2 3 4 5 6 7 8 9 10 11 12
 // 0 0 0
 // 1 0 0 1
 // 2   0 0

//               ^
//TODO like here |
std::vector<std::vector<int>> convertMapToGraph(std::vector<std::vector<int>> map) {
    std::vector<std::vector<int>> ret;
    //logic here
    return ret;
}

class Edge {
    int vertex;
    int weight;
};

class EdgeOther {
    int vertex1;
    int vertex2;
    int weight;
};
 // Adjacency List
 //             (v)(w)
 // adj[0] = [[1, 1], [2, 2]]
 // adj[1] = [[3, 5], [0, 1]]
 //                .
 // or
 // adj[int] = {Edge, Edge, Edge}

 // Adj list (unordered)
 // adj[] [[n1, n2, w], ...]
 // adj = [[0, 1, 1], [0, 2, 2], ...]
 // adj = [EdgeOther, EdgeOther, EdgeOther]
int graph_test()
{
    std::cout << "Simple Graph: \n";
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    //g.addEdge(1, 3);
    
    std::cout << "Matrix: \n";
    g.printMatrix();
 
    std::cout << "DFS: \n";
    g.DFS(2);

    g.convertToMatrix();

    std::cout << "\n";

    std::cout << "Weighted Graph: \n";
    WeightedGraph wg;
    wg.addEdge(0, 1, 1);
    wg.addEdge(0, 2, 2);
    wg.addEdge(1, 2, 3);
    wg.addEdge(2, 3, 4);
    wg.addEdge(2, 0, 4);
    wg.addEdge(1, 3, 5);
    wg.addEdge(3, 3, 6);

    std::cout << "Weighted Matrix: \n";
    wg.printMatrix();
 
    std::cout << "Weighted DFS: \n";
    wg.DFS(2);

    std::cout << "Weighted Kruskal's MST: \n";
    wg.kruskals_mst();

    std::cout << "\n";
 
    return 0;
}

}
