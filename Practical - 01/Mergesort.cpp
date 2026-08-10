#include <iostream>
using namespace std;

class MergeSort {
public:
    int size;
    int arr[100];

    void ArrayInput() {
        cout << "Enter the size of the array: ";
        cin >> size;

        cout << "Enter the array elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void printarray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void merge(int low, int mid, int high) {
        int temp[100];
        int i = low;
        int j = mid + 1;
        int k = low;

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= high) {
            temp[k++] = arr[j++];
        }

        for (i = low; i <= high; i++) {
            arr[i] = temp[i];
        }
    }

    void mergeLogic(int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;

            mergeLogic(low, mid);
            mergeLogic(mid + 1, high);
            merge(low, mid, high);
        }
    }
};

int main() {
    MergeSort ms;
    ms.ArrayInput();

    cout << "Before sorting: ";
    ms.printarray();

    ms.mergeLogic(0, ms.size - 1);

    cout << "After sorting: ";
    ms.printarray();

    return 0;
}