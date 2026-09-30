#include <iostream>
using namespace std;

class Graph {
public:
    int adj[10][10];
    int visited[10];
    int n;

    void getInput() {
        cout << "Enter number of vertices : ";
        cin >> n;

        cout << "Enter adjacency matrix (" << n << "x" << n << ") :" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> adj[i][j];
            }
        }
    }

    void resetVisited() {
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }
    }

    void BFS(int start) {
        int queue[10];
        int front = 0, rear = 0;

        resetVisited();

        queue[rear++] = start;
        visited[start] = 1;

        cout << "BFS Traversal : ";

        while (front < rear) {
            // dequeue
            int node = queue[front++];
            cout << node << " ";

            for (int i = 0; i < n; i++) {
                if (adj[node][i] == 1 && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
        }

        cout << endl;
    }

    void DFS(int node) {
        visited[node] = 1;
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                DFS(i);
            }
        }
    }

    void startDFS(int start) {
        resetVisited();

        cout << "DFS Traversal : ";
        DFS(start);
        cout << endl;
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:" << endl;
        cout << "  ";

        for (int i = 0; i < n; i++) {
            cout << i << " ";
        }

        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << i << " ";

            for (int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    Graph g;

    g.getInput();
    g.displayMatrix();

    int start;

    cout << "\nEnter starting vertex : ";
    cin >> start;

    cout << endl;

    g.BFS(start);
    g.startDFS(start);

    return 0;
}