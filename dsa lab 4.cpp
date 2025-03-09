#include<iostream>
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
    void insert_at_position(int data, int position) {
        if (position < 0) {
        cout << "Invalid position" << endl;
            return;
        }
        node* newnode = new node();
        newnode->data = data;
        newnode->next = nullptr;

        if (position == 0 || head == nullptr) {
            newnode->next = head;
            head = newnode;
        } else {
            node* temp = head;
            int currentposition = 0;
            while (temp->next != nullptr && currentposition < position - 1) {
                temp = temp->next;
                currentposition++;
            }
            if (currentposition != position - 1) {
                cout << "Invalid position" << endl;
                delete newnode;
                return;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    void displaylist() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    singlylinked linked;
    linked.insert_at_position(10, 0);
    linked.insert_at_position(20, 1);
    cout << "Linked list ";
    linked.displaylist();
    return 0;
}