#include <iostream>
using namespace std;

class InsertionSort {
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

    void insertionLogic() {
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }
};

int main() {
    InsertionSort is;
    is.ArrayInput();

    cout << "Before sorting: ";
    is.printarray();

    is.insertionLogic();

    cout << "After sorting: ";
    is.printarray();

    return 0;
}