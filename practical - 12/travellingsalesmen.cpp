#include <iostream>
using namespace std;

int main()
{
    int n, cost[100][100];
    bool visited[100] = {false};

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int current = 0;
    int totalCost = 0;

    visited[current] = true;

    cout << "\nTour: " << current;

    for (int count = 1; count < n; count++)
    {
        int min = 999999;
        int next = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && cost[current][j] < min)
            {
                min = cost[current][j];
                next = j;
            }
        }

        if (next == -1)
        {
            cout << "\nNo complete tour exists.";
            return 0;
        }

        totalCost += min;
        visited[next] = true;

        cout << " -> " << next;

        current = next;
    }

    totalCost += cost[current][0];

    cout << " -> 0";
    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}