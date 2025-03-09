#include <iostream>
using namespace std;
class node {
	public:
    int data;
    node* next;
     node(int val)  {
    	data=val;
    	next=nullptr;
	}
};


void displayfirstnode(node* head) {
    if (head != nullptr) {
        cout << "First node " << head->data << endl;
    } else {
        cout << "List is empty" << endl;
    }
}


void displaylastnode(node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    cout << "Last node " << temp->data << endl;
}


void displaynthnode(node* head, int n) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    node* temp = head;
    int count = 1;
    while (temp != nullptr && count < n) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Nth node does not exist" << endl;
    } else {
        cout << "Nth node position " << n  << temp->data << endl;
    }
}


void displaycenternode(node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    node* slow = head;
    node* fast = head;


    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    cout << "center node " << slow->data << endl;
}
void addnode(node*& head, int val) {
    node* newnode = new node(val);
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

int main() {
    node* head = nullptr;
    addnode(head, 1);
    addnode(head, 2);
    addnode(head, 3);
    addnode(head, 4);
    displayfirstnode(head);
    displaylastnode(head);
    displaynthnode(head, 2);
    displaycenternode(head);

    return 0;
}
