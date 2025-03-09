#include <iostream>
using namespace std;
class node {
	public:
    int data;
    node* next;
};
class singlylinked {
private:
    node* head;
public:
    singlylinked() {
        head = nullptr;
    }
    void insert_at_start(int data) {
        node* newnode = new node();
        newnode->data = data;
        newnode->next = head;
        head = newnode;
    }
    void insert_at_end(int data) {
        node* newnode = new node();
        newnode->data = data;
        newnode->next = nullptr;
        if (head == nullptr) {
            head = newnode;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }  
    void displaylist() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data ;
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    singlylinked linked;
    linked.insert_at_start(1);
    linked.insert_at_start(2);
    linked.insert_at_start(3);
    cout << "linked list  inserting at start ";
    linked.displaylist();
    linked.insert_at_end(4);
    linked.insert_at_end(5);
    linked.insert_at_end(6);
    cout << "linked list inserting at end ";
    linked.displaylist();
    return 0;
}

