#include <iostream>
using namespace std;

struct Edge
{
    int u, v, weight;
};

int parent[100];

int find(int x)
{
    while (parent[x] != x)
    {
        x = parent[x];
    }

    return x;
}

void sortEdges(Edge edges[], int e)
{
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int vertices, edgesCount;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edgesCount;

    Edge edges[100];

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < edgesCount; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
    }

    sortEdges(edges, edgesCount);

    int totalCost = 0;
    int selectedEdges = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < edgesCount && selectedEdges < vertices - 1; i++)
    {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v)
        {
            cout << edges[i].u << " - "
                 << edges[i].v << " = "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;
            parent[u] = v;
            selectedEdges++;
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}