#include <iostream>

using namespace std;

void SimpleSorting(int list[], int size);
void BubbleSorting(int list[], int size);
void SelectionSorting(int list[], int size);
void InsertionSorting(int list[], int size);
int LinearSearch(int list[], int size, int target);
int BinarySearch(int list[], int size, int target);
void displayList(int list[], int size);

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;
    int list[size];
    for (int i = 0; i < size; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> list[i];
    }

    cout << "List of the elements you entered is: ";
    displayList(list, size);

    int choose, select;
    cout << "Enter type of algorithm you wanted to compute:\n1 Sorting Algorithm.\n2 Searching Algorithm.\n";
    cin >> choose;

    if (choose == 1) {
        cout << "Enter type of Sorting algorithm you wanted to compute:\n1 Simple sorting.\n2 Bubble Sorting.\n3 Selection Sorting.\n4 Insertion Sorting.\n";
        cin >> select;

        cout << "List before sorted: ";
        displayList(list, size);

        switch (select) {
            case 1:
                SimpleSorting(list, size);
                cout << "List after sorted by simple sorting algorithm: ";
                break;
            case 2:
                BubbleSorting(list, size);
                cout << "List after sorted by bubble sorting algorithm: ";
                break;
            case 3:
                SelectionSorting(list, size);
                cout << "List after sorted by selection sorting algorithm: ";
                break;
            case 4:
                InsertionSorting(list, size);
                cout << "List after sorted by insertion sorting algorithm: ";
                break;
            default:
                cout << "Invalid selection.";
                return 1; // Exit if invalid selection
        }

        displayList(list, size);
    } else if (choose == 2) {
        int target;
        cout << "Enter the element to search for: ";
        cin >> target;

        // Linear Search
         int type;
         cout<<"Enter type of searching algorithm \n1 Linear Searching.\n2 Binary search.\n";
         cin>>type;
         if(type ==1){
        int index = LinearSearch(list, size, target);
        if (index != -1) {
            cout << "Element found at index " << index <<" computed by Linear Search"<< endl;
        } else {
            cout << "Element is not found by Linear Search." << endl;
        }}
    }
        // Binary Search
        // First, sort the list
        else{
        int target;
        cout << "Enter the element to search for: ";
        cin >> target;
        BubbleSorting(list, size); // Ensure the list is sorted
        int index = BinarySearch(list, size, target);
        if (index != -1) {
            cout << "Element found at index " << index <<"computed by Binary Search"<<endl;
        } else {
            cout << "Element is not found by Binary Search." << endl;
        }}
    return 0;
    }





void displayList(int list[], int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << list[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void SimpleSorting(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] > list[j]) {
                swap(list[i], list[j]);
            }
        }
    }
}

void BubbleSorting(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }
}

void SelectionSorting(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(list[i], list[min]);
        }
    }
}

void InsertionSorting(int list[], int size) {
    for (int i = 1; i < size; i++) {
        int temp = list[i];
        int j = i - 1;
        while (j >= 0 && list[j] > temp) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = temp;
    }
}

int LinearSearch(int list[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (list[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}

int BinarySearch(int list[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids potential overflow

        if (list[mid] == target) {
            return mid; // Element found
        }
        if (list[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}
