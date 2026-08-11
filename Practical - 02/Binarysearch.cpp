#include <iostream>
using namespace std;

int Binarysearch(int arr[], int n, int search)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == search)
        {
            return mid;
        }
        else if (arr[mid] < search)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int search;

    cout << "Enter element to search: ";
    cin >> search;

    int index = Binarysearch(arr, n, search);

    if (index != -1)
    {
        cout << "Element found at index " << index << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}