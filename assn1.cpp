#include<iostream>
#include<vector>
using namespace std;

float loadFactor(const vector<int>& arr) {
    int fac = arr.size();
    int ele = 0;
    for (auto it : arr) {
        if (it != -1 && it != -2) {
            ele++;
        }
    }
    cout << "Load factor is: " << (float)ele / fac << endl;
    return (float)ele / fac;
}

void insert(vector<int>& arr, int num) {
    int fac = arr.size(), pass = 0;
    int i = num % fac;
    while (arr[i] != -1) {
        i = (i + 1) % fac;
        pass++;
    }
    arr[i] = num;
    cout << "Number of passes: " << pass << endl;
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

int find(const vector<int>& arr, int num) {
    int fac = arr.size();
    int count = 0, pass = 0;
    int i = num % fac;

    while (arr[i] != -1 && count < fac) {
        if (arr[i] == num) {
            return i;
        }
        i = (i + 1) % fac;
        pass++;
        count++;
    }
    cout << "Number of passes: " << pass << endl;
    return -1;  
}

void remove(vector<int>& arr, int num) {
    int ans = find(arr, num);
    if (ans != -1) {
        arr[ans] = -2; 
    } else {
        cout << "Element not found\n";
    }
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
        cout << "4. Delete an element\n";
        cout << "5. Display load factor\n";
        cout << "6. Is full?\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
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
                if (find(arr, num) != -1) {
                    cout << "Element " << num << " found in the hash table.\n";
                } else {
                    cout << "Element " << num << " not found in the hash table.\n";
                }
                break;

            case 4:
                cout << "Enter a number to delete: ";
                cin >> num;
                remove(arr, num);
                break;

            case 5:
                loadFactor(arr);
                break;

            case 6:
                if (loadFactor(arr) == 1.0) {
                    cout << "Hash table is full\n";
                } else {
                    cout << "Hash table is not full\n";
                }
                break;

            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
