#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node() {
        this->data = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    ~Node() {
        cout << "The value = " << this->data << " is deleted" << endl;
    }
};

class LInList {
    Node* head;
    Node* tail;

public:
    // constructor
    LInList() {
        head = nullptr;
        tail = nullptr;
    }

    // destructor -> deletes whole list
    ~LInList() {
        while (head != nullptr) {
            delete_at_head();
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int find_length() {
        Node* temp = head;
        int len = 0;
        while (temp != nullptr) {
            temp = temp->next;
            len++;
        }
        return len;
    }

    void insert_at_head(int data) {
        if (head == nullptr) {
            Node* newnode = new Node(data);
            head = newnode;
            tail = newnode;
            return;
        }
        Node* newnode = new Node(data);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    void insert_at_tail(int data) {
        if (head == nullptr) {
            Node* newnode = new Node(data);
            head = newnode;
            tail = newnode;
            return;
        }
        Node* newnode = new Node(data);
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }

    void insert_at_position(int data, int pos) {
        if (pos == 0) {
            insert_at_head(data);
            return;
        }

        int len = find_length();
        if (pos < 0 || pos > len) {
            cout << "!POSITION OF INSERTION IS INVALID! " << data << " WAS NOT INSERTED " << endl;
            return;
        }

        if (pos == len) {
            insert_at_tail(data);
            return;
        }

        Node* temp = head;
        int i = 0;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        Node* curr = temp->next;
        Node* newnode = new Node(data);
        newnode->next = curr;
        newnode->prev = temp;
        temp->next = newnode;
        curr->prev = newnode;
    }

    void delete_at_head() {
        if (head == nullptr) {
            cout << "!INVALID DELETION!" << endl;
            return;
        }
        if (head == tail) { // only one node
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = temp->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
    }

    void delete_at_tail() {
        if (head == nullptr) {
            cout << "!INVALID DELETION!" << endl;
            return;
        }
        if (head == tail) { // only one node
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = tail;
        tail = temp->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }

    void delete_at_position(int pos) {
        if (head == nullptr) {
            cout << "!INVALID DELETION!" << endl;
            return;
        }

        if (pos == 0) {
            delete_at_head();
            return;
        }

        int len = find_length();
        if (pos < 0 || pos > len - 1) {
            cout << "!POSITION OF DELETION IS INVALID!" << endl;
            return;
        }

        if (pos == len - 1) {
            delete_at_tail();
            return;
        }

        Node* temp = head;
        int i = 0;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        Node* curr = temp->next;
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = nullptr;
        curr->prev = nullptr;
        delete curr;
    }
};

int main() {
    LInList dll;
    dll.insert_at_head(145);
    dll.insert_at_head(22);
    dll.insert_at_head(33);
    dll.insert_at_head(49);
    dll.insert_at_tail(100);
    dll.delete_at_position(4);

    cout << "The Doubly linked list contains values = ";
    dll.print();
}
