#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100; // Maximum number of vertices in the graph

// Global variables
vector<int> adj[MAX]; // Adjacency list for the graph
bool visited[MAX];    // Array to keep track of visited vertices

// Function to add an edge to the graph
void addEdge(int v, int w) {
    adj[v].push_back(w);
}

// Function for Breadth-First Search (BFS) traversal of the graph from a given source vertex
void BFS(int s) {
    // Clear the visited array
    fill(visited, visited + MAX, false);

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        for (int i = 0; i < adj[s].size(); i++) {
            int adjVertex = adj[s][i];
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
}

// Recursive helper function for Depth-First Search (DFS)
void DFSUtil(int v) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < adj[v].size(); i++) {
        int adjVertex = adj[v][i];
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex);
        }
    }
}

// Function for Depth-First Search (DFS) traversal of the graph from a given source vertex
void DFS(int s) {
    // Clear the visited array
    fill(visited, visited + MAX, false);

    // Call the recursive helper function to perform DFS traversal
    DFSUtil(s);
}

// Main function
int main() {
    // Add edges to the graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    addEdge(3, 4);

    cout << "Breadth-First Search (starting from vertex 2): ";
    BFS(2);

    cout << "\nDepth-First Search (starting from vertex 2): ";
    DFS(2);

    return 0;
}
