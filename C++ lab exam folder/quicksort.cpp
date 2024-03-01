#include <iostream>
using namespace std;
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main() {
    int n;
    cout<<"Enter array size";
    cin>>n;
    int intArray[n];double doubarray[n];
    cout<<"Enter "<<n<<" integer array elements";
    for(int i=0;i<n;i++)
    {
        cin>>intArray[i];
    }

    cout << "Original Array: ";
    printArray(intArray, n);

    quickSort(intArray, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(intArray, n);
    cout<<"Enter "<<n<<" double array elements";
    for(int i=0;i<n;i++)
    {
        cin>>doubarray[i];
    }
    cout << "Original Array: ";
    printArray(doubarray, n);

    quickSort(doubarray, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(doubarray, n);
    return 0;
}
