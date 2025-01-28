#include <iostream>
#include <map>
using namespace std;

const int tableSize = 10;
map<int, pair<int, int>> table;

int hashFunction(int key) {
    return key % tableSize;
}

void insert(int key) {
    int index = hashFunction(key);
    if (table[index].first == -1) {
        table[index].first = key;
    } else {
        int replace = table[index].first;
        int next1 = table[index].second;
        int key1 = hashFunction(replace);
        if (key1 == index) {
            int current = index;
            while (table[current].second != -1) {
                current = table[current].second;
            }
            int nextSlot = (current + 1) % tableSize;
            while (table[nextSlot].first != -1 && nextSlot != current) {
                nextSlot = (nextSlot + 1) % tableSize;
            }
            if (table[nextSlot].first== -1) {
                table[nextSlot].first =key;
                table[current].second = nextSlot;
            }
        } else {
            int prev = 0;
            while (table[key1].first != replace) {
                prev = key1;
                key1 = table[key1].second;
            }
            table[index].first = key;
            int next = (key1 + 1) % tableSize;
            while (table[next].first != -1 && next != key1) {
                next = (next + 1) % tableSize;
            }
            if (table[next].first == -1) {
                table[next].first = replace;
                table[prev].second = next;
                table[next].second = next1;
            }
        }
    }
}

bool search(int key) {
    int index = hashFunction(key);
    while (index != -1) {
        if (table[index].first == key) {
            return true;
        }
        index = table[index].second;
    }
    return false;
}

void deleteKey(int key) {
    int index = hashFunction(key);
    int prev = -1;
    while (index != -1) {
        if (table[index].first == key) {
            table[index].first = -1; 
            if (prev != -1) {
                table[prev].second = table[index].second;
            }
            table[index].second = -1;
            cout << "Key " << key << " deleted successfully.\n";
            return;
        }
        prev = index;
        index = table[index].second;
    }
    cout << "Key " << key << " not found in the hash table.\n";
}

void display() {
    for (int i = 0; i < tableSize; i++) {
        cout << "Slot " << i << ": " << table[i].first;
        cout << " -> " << table[i].second;
        cout << endl;
    }
}

int main() {
   
    for (int i = 0; i < tableSize; i++) {
        table[i] = {-1, -1};
    }

    int choice, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key to insert: ";
                cin >> key;
                insert(key);
                break;
            case 2:
                cout << "Enter the key to search: ";
                cin >> key;
                if (search(key)) {
                    cout << "Key " << key << " found in the hash table.\n";
                } else {
                    cout << "Key " << key << " not found in the hash table.\n";
                }
                break;
            case 3:
                cout << "Enter the key to delete: ";
                cin >> key;
                deleteKey(key);
                break;
            case 4:
                cout << "Hash table: \n";
                display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
