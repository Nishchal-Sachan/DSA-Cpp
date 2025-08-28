#include<iostream>
using namespace std;

// Graph class to represent adjacency matrix
class Graph {
    public:
    int** adjMatrix;   // Pointer to a 2D dynamic array (matrix)
    int numNodes;      // Number of nodes in the graph

    // Constructor: initialize the adjacency matrix
    Graph(int nodes) {
        this->numNodes = nodes;

        // Allocate memory for rows
        adjMatrix = new int*[nodes];

        // Allocate memory for columns in each row
        for(int i = 0; i < nodes; i++) {
            adjMatrix[i] = new int[nodes];

            // Initialize all entries to 0 (no edges yet)
            for(int j = 0; j < nodes; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Function to add an edge between u and v
    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed

        adjMatrix[u][v] = 1; // Add edge u → v

        if(direction == 0) {
            adjMatrix[v][u] = 1; // If undirected, also add v → u
        }
    }

    // Function to print adjacency matrix
    void printAdjMatrix() {
        cout << "Adjacency Matrix Representation:" << endl;
        for(int i = 0; i < numNodes; i++) {
            for(int j = 0; j < numNodes; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor: free dynamically allocated memory
    ~Graph() {
        for(int i = 0; i < numNodes; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    // Create a graph with 4 nodes (0,1,2,3)
    Graph g(4);

    // Add edges
    g.addEdge(0, 1, 0); // Edge between 0 and 1 (undirected)
    g.addEdge(0, 2, 1); // Edge from 0 to 2 (directed)
    g.addEdge(1, 2, 0); // Edge between 1 and 2 (undirected)
    g.addEdge(2, 3, 1); // Edge from 2 to 3 (directed)

    // Print adjacency matrix
    g.printAdjMatrix();

    return 0;
}
