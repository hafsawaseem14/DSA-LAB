#include <iostream>
using namespace std;

#define size 100
class stackarray {
private:
    int arr[size];
    int top;
public:
    stackarray() {
        top = -1;
    }
void push(int value) {
        if (top >= size - 1) {
            cout << "stack overflow"<<endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack"<<endl;
        }
    }
    void pop() {
        if (top < 0) {
            cout << "stack underflow"<<endl;
        } else {
            cout << arr[top--] << " popped from stack"<<endl;
        }
    }
    void display() {
        if (top < 0) {
            cout << "stack is empty"<<endl;
        } else {
            cout << "stack elements"<<endl;
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
    }
};
int main() {
    stackarray arr;
   cout << " stack using array "<<endl;
    arr.push(10);
    arr.push(20);
    arr.display();
    arr.pop();
    arr.display();

}
//with linked list 
struct node {
    int data;
    node* next;
};
class stacklinkedlist {
private:
    node* top;
public:
    stacklinkedlist() {
        top = NULL;
    }
    void push(int value) {
        node* newnode = new node();
        newnode->data = value;
        newnode->next = top;
        top = newnode;
        cout << value << " pushed into stack"<<endl;
    }
    void pop() {
        if (top == NULL) {
            cout << "stack underflow"<<endl;
        } else {
            node* temp = top;
            cout << top->data << " popped from stack"<<endl;
            top = top->next;
            delete temp;
        }
    }
    void display() {
        if (top == NULL) {
            cout << "stack is empty"<<endl;
        } else {
            cout << "stack elements"<<endl;
            node* temp = top;
            while (temp != NULL) {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};
int main() {
    stacklinkedlist list; 
    cout << "stack using linked list ";
   	list.push(10);
    list.push(20);
    list.display();
    list.pop();
    list.display();
}
