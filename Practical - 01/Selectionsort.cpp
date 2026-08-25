#include <iostream>
using namespace std;

class SelectionSort {
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

    void selectionLogic() {
        for (int i = 0; i < size - 1; i++) {
            int min = i;

            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
};

int main() {
    SelectionSort ss;
    ss.ArrayInput();

    cout << "Before sorting: ";
    ss.printarray();

    ss.selectionLogic();

    cout << "After sorting: ";
    ss.printarray();

    return 0;
}