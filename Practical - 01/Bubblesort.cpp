#include <iostream>
using namespace std;

class BubbleSort {
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

    void bubbleLogic() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    BubbleSort bs;
    bs.ArrayInput();

    cout << "Before sorting: ";
    bs.printarray();

    bs.bubbleLogic();

    cout << "After sorting: ";
    bs.printarray();

    return 0;
}