#include<iostream>
#include<vector>
using namespace std;

// Hash function
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

// Insert function
void insert(vector<vector<int>>& hashTable, int num) {
    int index = hashFunction(num, hashTable.size());
    hashTable[index].push_back(num);
    cout << "Inserted " << num << " at index " << index << endl;
}

// Display the hash table
void display(const vector<vector<int>>& hashTable) {
    for (int i = 0; i < hashTable.size(); ++i) {
        cout << "Index " << i << ": ";
        if (hashTable[i].empty()) {
            cout << "Empty" << endl;
        } else {
            for (int val : hashTable[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
}

// Find an element in the hash table
bool find(const vector<vector<int>>& hashTable, int num) {
    int index = hashFunction(num, hashTable.size());
    for (int val : hashTable[index]) {
        if (val == num) {
            return true;
        }
    }
    return false;
}

// Remove an element from the hash table
void remove(vector<vector<int>>& hashTable, int num) {
    int index = hashFunction(num, hashTable.size());
    for (auto it = hashTable[index].begin(); it != hashTable[index].end(); ++it) {
        if (*it == num) {
            hashTable[index].erase(it);
            cout << "Removed " << num << " from index " << index << endl;
            return;
        }
    }
    cout << "Element " << num << " not found.\n";
}

// Calculate and display the load factor of the hash table
void loadFactor(const vector<vector<int>>& hashTable) {
    int totalElements = 0;
    for (int i = 0; i < hashTable.size(); ++i) {
        totalElements += hashTable[i].size();
    }
    cout << "Load factor is: " << (float)totalElements / hashTable.size() << endl;
}

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    // Initialize the hash table with empty vectors
    vector<vector<int>> hashTable(size);

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
                insert(hashTable, num);
                break;

            case 2:
                cout << "\nHash Table:\n";
                display(hashTable);
                break;

            case 3:
                cout << "Enter a number to find: ";
                cin >> num;
                if (find(hashTable, num)) {
                    cout << "Element " << num << " found in the hash table.\n";
                } else {
                    cout << "Element " << num << " not found in the hash table.\n";
                }
                break;

            case 4:
                cout << "Enter a number to delete: ";
                cin >> num;
                remove(hashTable, num);
                break;

            case 5:
                loadFactor(hashTable);
                break;

            case 6:
                if ((float)hashTable.size() == 1) {
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
