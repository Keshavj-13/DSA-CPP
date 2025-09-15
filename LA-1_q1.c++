#include <iostream>
using namespace std;

int main() {
    int arr[100], size = 0;
    int choice, pos, element;

    while(true) {
        cout << "\n----- MENU -----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n"; 
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: // Create
                cout << "Enter size of array: ";
                cin >> size;
                cout << "Enter " << size << " elements: ";
                for(int i = 0; i < size; i++)
                    cin >> arr[i];
                break;

            case 2: // Display
                if(size == 0) {
                    cout << "Array is empty\n";
                    break;
                }
                cout << "Array elements: ";
                for(int i = 0; i < size; i++)
                    cout << arr[i] << " ";
                cout << endl;
                break;

            case 3: // Insert
                cout << "Enter elements  and postions: ";
                cin >> pos >> element;
                if(pos < 0 || pos > size) {
                    cout << "Invalid position\n";
                    break;
                }
                for(int i = size; i > pos; i--)
                    arr[i] = arr[i-1];
                arr[pos] = element;
                size++;
                break;

            case 4: // Delete
                cout << "Enter position: ";
                cin >> pos;
                if(pos < 0 || pos >= size) {
                    cout << "Invalid position\n";
                    break;
                }
                for(int i = pos; i < size-1; i++)
                    arr[i] = arr[i+1];
                size--;
                break;

            case 5: // Linear Search
                cout << "Enter element to search: ";
                cin >> element;
                for(int i = 0; i < size; i++) {
                    if(arr[i] == element) {
                        cout << "Element found at position " << i << endl;
                        break;
                    }
                    if(i == size-1)
                        cout << "Element not found\n";
                }
                break;

            case 6: // Exit
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}