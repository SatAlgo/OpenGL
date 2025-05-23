#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


class HashTable {
private:
    int TABLE_SIZE;
    list<int>* table;

public:
    HashTable(int size) {
        TABLE_SIZE = size;
        table = new list<int>[TABLE_SIZE];
    }

    ~HashTable() {
        delete[] table;
    }

    
    int HashFunc(int key) {
        return key % TABLE_SIZE;
    }

    
    void Insert(int key) {
        int hash_val = HashFunc(key);
        table[hash_val].push_back(key);
        cout << "Inserted key " << key << " at index " << hash_val << endl;
    }

    void Remove(int key) {
        int hash_val = HashFunc(key);
        list<int>& list_at_index = table[hash_val];
        auto it = find(list_at_index.begin(), list_at_index.end(), key);
        
        if (it != list_at_index.end()) {
            list_at_index.erase(it);
            cout << "Key " << key << " removed from index " << hash_val << endl;
        } else {
            cout << "Key " << key << " not found in the hash table." << endl;
        }
    }

   
    bool Search(int key) {
        int hash_val = HashFunc(key);
        for (const int& it : table[hash_val]) {
            if (it == key) {
                cout << "Key " << key << " found at index " << hash_val << endl;
                return true;
            }
        }
        cout << "Key " << key << " not found in the hash table." << endl;
        return false;
    }


    void Display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            if (table[i].empty()) {
                cout << "NULL" << endl;
            } else {
                for (const int& it : table[i]) {
                    cout << it << " -> ";
                }
                cout << "NULL" << endl;
            }
        }
    }
};


int main() {
    
    int data[] = {33, 56, 78, 12, 10, 67, 89, 99, 100, 23, 45, 71, 39, 62, 59, 90, 91, 20, 75, 66};
    int n = sizeof(data) / sizeof(data[0]);

    HashTable hash(20);


    for (int i = 0; i < n; i++) {
        hash.Insert(data[i]);
    }

   
    cout << "\nHash Table Contents:\n";
    hash.Display();

    
    int searchKey = 78;
    cout << "\nSearching for key " << searchKey << ":\n";
    hash.Search(searchKey);

    
    int removeKey = 45;
    cout << "\nRemoving key " << removeKey << ":\n";
    hash.Remove(removeKey);

   
    cout << "\nHash Table after removal:\n";
    hash.Display();

    return 0;
}

