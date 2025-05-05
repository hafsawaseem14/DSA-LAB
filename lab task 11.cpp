#include <iostream>
using namespace std;

class arrayqueue {
private:
    int *queue;
    int front, rear, size;

public:
    arrayqueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue overflow";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow";
            return;
        }
        cout << "Dequeued " << queue[front] << endl;
        front++;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty";
            return;
        }
        cout << "Queue elements ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    cout << "Array-based Queue ";
    arrayqueue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    queue.dequeue();
    queue.display();

    
    return 0;
}
//with linkedlist 
//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* next;
//};
//
//class Linkedlistqueue {
//private:
//    Node *front, *rear;
//
//public:
//    Linkedlistqueue() {
//        front = rear = nullptr;
//    }
//
//    void enqueue(int value) {
//        Node* newNode = new Node{value, nullptr};
//        if (rear == nullptr) {
//            front = rear = newNode;
//            return;
//        }
//        rear->next = newNode;
//        rear = newNode;
//    }
//
//    void dequeue() {
//        if (front == nullptr) {
//            cout << "Queue underflow";
//            return;
//        }
//        Node* temp = front;
//        cout << "Dequeued " << temp->data << endl;
//        front = front->next;
//        if (front == nullptr)
//            rear = nullptr;
//        delete temp;
//    }
//
//    void display() {
//        if (front == nullptr) {
//            cout << "Queue is empty";
//            return;
//        }
//        cout << "Queue elements ";
//        Node* temp = front;
//        while (temp) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//};
//int main() {
//    cout << " Linked list-based queue ";
//    Linkedlistqueue queue;
//    queue.enqueue(10);
//    queue.enqueue(20);
//    queue.enqueue(30);
//    queue.display();
//    queue.dequeue();
//    queue.display();
//
//    return 0;
//}
