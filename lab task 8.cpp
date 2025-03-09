#include <iostream>
using namespace std;
class singlynode {
	public:
    int data;
    singlynode* next;
    singlynode(int val) {
    	data=val;
    	next=nullptr;
	}
};
class singlylinkedlist {
public:
    singlynode* head;

    singlylinkedlist() {
	 head=nullptr; 
}
    
    void insert_at_last(int data) {
        singlynode* newnode = new singlynode(data);
        if (!head) {
            head = newnode;
        } else {
            singlynode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    singlynode* merge(singlylinkedlist& other) {
        if (!head) return other.head;
        if (!other.head) return head;

        singlynode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = other.head;

        return head;
    }

    
    void displaylist() {
        singlynode* temp = head;
        if (!temp) {
            cout << "List is empty" << endl;
            return;
        }
    while (temp) {
            cout << temp->data ;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    singlylinkedlist list1, list2;
    list1.insert_at_last(1);
    list1.insert_at_last(2);
    list1.insert_at_last(3);
    list2.insert_at_last(4);
    cout << "List 1 ";
    list1.displaylist();
    cout << "List 2 ";
    list2.displaylist();
    list1.merge(list2);
	cout << "Merged list";
    list1.displaylist();

    return 0;
}
