#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int>& arr, int num) {
    int fac = arr.size();
    int i = num % fac;
    while (arr[i] != -1) {
        i = (i + 1) % fac;
    }
    arr[i] = num;
}

void display(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != -1) {
            cout << "Index " << i << ": " << arr[i] << endl;
        } else {
            cout << "Index " << i << ": Empty" << endl;
        }
    }
}

bool find(const vector<int>& arr, int num) {
    int fac = arr.size();
    int i = num % fac;
    int count = 0;

    while (arr[i] != -1 && count < fac) {
        if (arr[i] == num) {
            return true;
        }
        i = (i + 1) % fac;
        count++;
    }

    return false;
}

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    vector<int> arr(size, -1);

    int choice, num;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Display the hash table\n";
        cout << "3. Find an element\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter a number to insert: ";
                cin >> num;
                insert(arr, num);
                break;

            case 2:
                cout << "\nHash Table:\n";
                display(arr);
                break;

            case 3:
                cout << "Enter a number to find: ";
                cin >> num;
                if (find(arr, num)) {
                    cout << "Element " << num << " found in the hash table.\n";
                } else {
                    cout << "Element " << num << " not found in the hash table.\n";
                }
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
