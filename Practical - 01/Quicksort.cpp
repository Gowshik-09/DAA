#include <iostream>
using namespace std;

class QuickSort {
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

    int partition(int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    void quickLogic(int low, int high) {
        if (low < high) {
            int loc = partition(low, high);

            quickLogic(low, loc - 1);
            quickLogic(loc + 1, high);
        }
    }
};

int main() {
    QuickSort qs;
    qs.ArrayInput();

    cout << "Before sorting: ";
    qs.printarray();

    qs.quickLogic(0, qs.size - 1);

    cout << "After sorting: ";
    qs.printarray();

    return 0;
}