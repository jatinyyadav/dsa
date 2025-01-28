#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string word;
    string meaning;
    Node* next;

    Node(const string &w, const string &m) : word(w), meaning(m), next(nullptr) {}
};

class HashTable {
private:
    vector<Node*> table;
    int size;

    int hashFunction(const string &word) {
        int hashValue = 0;
        int multiplier = 1;

        for (int i = word.length() - 1; i >= 0; --i) {
            hashValue += static_cast<int>(word[i]) * multiplier;
            multiplier *= 10;
        }

        return hashValue % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size, nullptr);
    }

    void insert(const string &word, const string &meaning) {
        int index = hashFunction(word);
        Node* newNode = new Node(word, meaning);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void search(const string &word) {
        int index = hashFunction(word);
        Node* current = table[index];
        while (current) {
            if (current->word == word) {
                cout << "Meaning of '" << word << "': " << current->meaning << endl;
                return;
            }
            current = current->next;
        }
        cout << "'" << word << "' not found in the dictionary." << endl;
    }

    void printTable() {
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            if (current) {
                cout << "Index " << i << ": ";
                while (current) {
                    cout << "[" << current->word << ": " << current->meaning << "] ";
                    current = current->next;
                }
                cout << endl;
            }
        }
    }

    // ~HashTable() {
    //     for (int i = 0; i < size; i++) {
    //         Node* current = table[i];
    //         while (current) {
    //             Node* temp = current;
    //             current = current->next;
    //             delete temp;
    //         }
    //     }
    // }
};

int main() {
    HashTable hashTable(10);

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Word and Meaning" << endl;
        cout << "2. Search Word" << endl;
        cout << "3. Print Hash Table" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string word, meaning;
            cout << "Enter word: ";
            cin >> word;
            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, meaning);
            hashTable.insert(word, meaning);
            cout << "Word and meaning added!" << endl;
        }
        else if (choice == 2) {
            string word;
            cout << "Enter word to search: ";
            cin >> word;
            hashTable.search(word);
        }
        else if (choice == 3) {
            hashTable.printTable();
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}
