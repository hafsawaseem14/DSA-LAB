#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = nullptr;
    }
};
class circularlinkedlist {
private:
    node* head;
public:
    circularlinkedlist() {
        head = nullptr;
    }

    void insert_at_first(int data) {
        node* newnode = new node(data);
        if (!head) {
            head = newnode;
            newnode->next = head;
        } else {
            node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    void insert_at_last(int data) {
        node* newnode = new node(data);
        if (!head) {
            head = newnode;
            newnode->next = head;
        } else {
            node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
        }
    }

    void insert_at_nthnode(int data, int position) {
        if (position == 1) { 
            insert_at_first(data); 
            return; 
        }
        node* newnode = new node(data);
        node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; i++) 
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void insert_at_center(int data) {
        if (!head) { 
            insert_at_first(data); 
            return; 
        }
        node* slow = head, *fast = head;
        while (fast->next != head && fast->next->next != head) { 
            slow = slow->next; 
            fast = fast->next->next;
        }
        node* newnode = new node(data);
        newnode->next = slow->next;
        slow->next = newnode;
    }

    void displayforwardlist() {
        if (!head) return;
        node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayreverselist(node* node) {
        if (node->next == head) {
            cout << node->data << " ";
            return;
        }
        displayreverselist(node->next);
        cout << node->data << " ";
    }

    void displayreverselist() {
        if (!head) return;
        displayreverselist(head);
        cout << endl;
    }
};

int main() {
    circularlinkedlist list;
    list.insert_at_first(1);
    list.insert_at_first(4);
    list.insert_at_last(8);
    list.insert_at_last(3);
    list.insert_at_nthnode(5, 2);
    list.insert_at_center(30);

    cout << "List in forward order: ";
    list.displayforwardlist();
    cout << "List in reverse order: ";
    list.displayreverselist();
    return 0;
}
