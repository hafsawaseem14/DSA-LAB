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
void deletefirstnode(node*& head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    head = head->next; 
    delete temp; 
    cout << "First node deleted." << endl;
}
void deletelastnode(node*& head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Last node deleted" << endl;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr && temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next; 
    temp->next = nullptr; 
    cout << "Last node deleted." << endl;
}
void deletenthnode(node*& head, int n) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (n == 1) {
        deletefirstnode(head);
        return;
    }

    node* temp = head;
    int count = 1;
    while (temp != nullptr && count < n - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Nth node doesn't exist" << endl;
        return;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete; 
    cout << "Nth node deleted at position " << n  << endl;
}
void deletecenternode(node*& head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Center node  deleted" << endl;
        return;
    }

    node* slow = head;
    node* fast = head;
    node* prev = nullptr;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }


    if (prev != nullptr) {
        prev->next = slow->next; 
        delete slow; 
        cout << "Center node deleted" << endl;
    }
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
void displaylist(node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data ;
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    node* head = nullptr;
    addnode(head, 1);
    addnode(head, 2);
    addnode(head, 3);
    addnode(head, 4);
   
    cout << "Original list ";
    displaylist(head);
    deletefirstnode(head);
    cout << "List after deleting first node ";
    displaylist(head);
    deletelastnode(head);
    cout << "List after deleting last node ";
    displaylist(head);
    deletenthnode(head, 3);
    cout << "List after deleting 3rd node";
    displaylist(head);
    deletecenternode(head);
    cout << "List after deleting center node ";
    displaylist(head);

    return 0;
}
