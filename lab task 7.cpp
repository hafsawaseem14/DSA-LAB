#include<iostream>
using namespace std;
class node {
	public:
    int data;
    node* next;
    node* prev;
    node(int val) {
    	data =val;
    	next=nullptr;
    	prev=nullptr;
	}
};
class doublylinkedlist {
private:
    node* head;
    node* tail;

public:
    doublylinkedlist() {
    	head=nullptr;
    	tail=nullptr;
	}

    void insert_at_first(int data) {
        node* newnode = new node(data);
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void insert_at_last(int data) {
        node* newnode = new node(data);
        if (tail == nullptr) {
            head = tail = newnode;
        } else {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
    }


    void insert_at_nth(int data, int position) {
        if (position < 1) {
            cout << "Position should be greater than 0" << endl;
            return;
        }

        if (position == 1) {
            insert_at_first(data);
            return;
        }

        node* newnode = new node(data);
        node* current = head;
        int count = 1;

        while (current != nullptr && count < position) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Position exceeds the length of the list. Inserting at the end." << endl;
            insert_at_last(data);
        } else {
            newnode->next = current;
            newnode->prev = current->prev;
            current->prev->next = newnode;
            current->prev = newnode;
        }
    }
     void insert_at_center(int data) {
        if (head == nullptr) {
            insert_at_first(data);
            return;
        }

        node* slow = head;
        node* fast = head;

        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        node* newnode = new node(data);
        newnode->next = slow->next;
        newnode->prev = slow;

        if (slow->next != nullptr) {
            slow->next->prev = newnode;
        }
        slow->next = newnode;
    }

    
    void displayforward() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        node* current = head;
        while (current != nullptr) {
            cout << current->data ;
            current = current->next;
        }
        cout << endl;
    }

    
    void displayreverse() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        node* current = tail;
        while (current != nullptr) {
            cout << current->data ;
            current = current->prev;
        }
        cout << endl;
    }
};
int main() {
    doublylinkedlist list;
    list.insert_at_first(1);
    list.insert_at_first(5);
    list.insert_at_last(2);
    list.insert_at_last(3);
    list.insert_at_nth(4,5);  
    list.insert_at_center(6);   
    cout << "List in forward order ";
    list.displayforward();
    cout << "List in reverse order ";
    list.displayreverse();

    return 0;
}
