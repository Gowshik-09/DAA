#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 1000000000;

int main() {
    int n;
    int cost[MAX][MAX];
    bool visited[MAX] = {false};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];

            if (i == j)
                cost[i][j] = INF;
            else if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = true;

    int edges = 0;
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int minCost = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < minCost) {
                        minCost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1 || v == -1) {
            cout << "Graph is disconnected.\n";
            return 0;
        }

        cout << u << " - " << v
             << " : " << minCost << endl;

        totalCost += minCost;
        visited[v] = true;
        edges++;
    }

    cout << "\nTotal MST Cost = " << totalCost << endl;

    return 0;
}
