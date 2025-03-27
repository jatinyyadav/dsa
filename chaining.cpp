#include <iostream>
#include <vector>
using namespace std;

int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

void insert(vector<vector<int>>& hashTable, int num) {
    int index = hashFunction(num, hashTable.size());
    hashTable[index].push_back(num);
    cout << "Inserted " << num << " at index " << index << endl;
}

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

bool find(const vector<vector<int>>& hashTable, int num) {
    int index = hashFunction(num, hashTable.size());
    for (int val : hashTable[index]) {
        if (val == num) {
            return true;
        }
    }
    return false;
}

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

float loadFactor(const vector<vector<int>>& hashTable) {
    int totalElements = 0;
    for (int i = 0; i < hashTable.size(); ++i) {
        totalElements += hashTable[i].size();
    }
    float lf = (float)totalElements / hashTable.size();
    cout << "Load factor is: " << lf << endl;
    return lf;
}

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    if (cin.fail() || size <= 0) {
        cout << "Invalid size! Exiting.\n";
        return 1;
    }

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
                if (loadFactor(hashTable) >= 10.0) {  // Arbitrary threshold
                    cout << "Hash table is effectively full\n";
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
