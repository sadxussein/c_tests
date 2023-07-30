#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(nullptr),next(nullptr),key(k),value(val){};
};

class Cache{

protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache: public Cache {
public:
    LRUCache(int capacity) {
        cp = capacity;
        tail = nullptr;
        head = nullptr;
    };

    int get(int key) override {
        try {
            return mp.at(key)->value;
        } catch (out_of_range& oor) {
            return -1;
        }
    }

    void set(int key, int value) override {
        try {
            mp.at(key);
            if (mp[key] != head && mp.size() > 1) {
                if (mp[key] == tail) {
                    mp[key]->next->prev = nullptr;
                    tail = mp[key]->next;
                } else {
                    mp[key]->prev->next = mp[key]->next;
                    mp[key]->next->prev = mp[key]->prev;
                }
                mp[key]->prev = head;
                mp[key]->next = nullptr;
                head->next = mp[key];
                head = mp[key];
            }
            mp[key]->value = value;
        } catch (out_of_range& oor) {
            if (mp.empty()) {
                mp[key] = new Node(key, value);
                tail = mp[key];
            } else if (mp.size() == 1) {
                mp[key] = new Node(key, value);
                head = mp[key];
                head->prev = tail;
                tail->next = head;
            } else if (mp.size() >= 2 && mp.size() != cp) {
                mp[key] = new Node(key, value);
                mp[key]->prev = head;
                head->next = mp[key];
                head = mp[key];
            } else {
                mp[key] = new Node(key, value);
                mp[key]->prev = head;
                head = mp[key];
                tail = tail->next;
                mp.erase(tail->prev->key);
                tail->prev = nullptr;
            }
        }
//        Node* curr = head;
//        cout << "current list of Nodes:" << endl;
//        while (curr != nullptr) {
//            cout << curr->key << ' ' << curr->value << endl;
//            curr = curr->prev;
//        }
    }
};

int main() {
    int n, capacity,i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for(i=0;i<n;i++) {
        string command;
        cin >> command;
        if(command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if(command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
    }
    return 0;
}
