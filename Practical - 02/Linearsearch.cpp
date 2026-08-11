#include <iostream>
using namespace std;

int Linearsearch(int arr[], int n, int search)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int search;

    cout << "Enter element to search: ";
    cin >> search;

    int index = Linearsearch(arr, n, search);

    if (index != -1)
    {
        cout << "Element found at index " << index << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    delete[] arr;

    return 0;
}