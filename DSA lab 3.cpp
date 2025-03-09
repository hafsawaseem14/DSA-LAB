
#include <iostream>
using namespace std;
//class Node {
//public:
//    int data;  
//    Node* next; 
//    Node(int val) : data(val), next(nullptr) {}
//};
//
//int main() {
//
//    Node* head = new Node(10);
//    head->next = new Node(20);
//
//    if (head != nullptr) {
//        cout << "First node data: " << head->data << endl;
//    } else {
//        cout << "The list is empty." << endl;
//    }
//
//    delete head->next;
//    delete head;
//
//    return 0;
//}
//class Node {
//public:
//    int data;  
//    Node* next; 
//
//    Node(int val) : data(val), next(nullptr) {}
//};
//
//int main() {
//    Node* head = new Node(10);
//
//    head->next = new Node(20);
//    head->next->next = new Node(30);
//
//    Node* temp = head;
//    while (temp != nullptr && temp->next != nullptr) {
//        temp = temp->next; 
//    }
//
//    if (temp != nullptr) {
//        cout << "Last node data: " << temp->data << endl;
//    } else {
//        cout << "The list is empty." << endl;
//    }
//
//    delete head->next->next;
//    delete head->next;
//    delete head;
//
//    return 0;
//}

class Node {
public:
    int data;  
    Node* next; 

    
    Node(int val) : data(val), next(nullptr) {}
};

void displayNodeAtPosition(Node* head, int position) {
    Node* temp = head;
    int count = 1;  
    while (temp != nullptr && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr) {
        cout << "Node at position " << position << " has data: " << temp->data << endl;
    } else {
        cout << "Position " << position << " is out of bounds." << endl;
    }
}

int main() {
    
    Node* head = new Node(10);
    
    
    head->next = new Node(20);
    
    
    head->next->next = new Node(30);
    
    head->next->next->next = new Node(40);

    
    displayNodeAtPosition(head, 3); 
    displayNodeAtPosition(head, 5); 

    
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    
	
	delete head;

    return 0;
}

