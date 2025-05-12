#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    string operation;
    int result;
    Node* next;

    Node(string op, int res) {
        operation = op;
        result = res;
        next = nullptr;
    }
};

class Linkedlist {
private:
    Node* head;

public:
    Linkedlist() {
        head = nullptr;
    }

    void add(string op, int res) {
        Node* newNode = new Node(op, res);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->operation << " = " << temp->result << endl;
            temp = temp->next;
        }
    }

    void extractResults(int arr[], int& size) {
        Node* temp = head;
        size = 0;
        while (temp) {
            arr[size++] = temp->result;
            temp = temp->next;
        }
    }
};

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
	int result = 0, num1, num2, choice;
    char cont;
    stack<int> undoStack;
    Linkedlist history;

    do {
        cout << "\nCurrent result: " << result << endl;
        cout << "1. Add"<<endl;
        cout<<"2. Subtract"<<endl;
		cout<<"3. Multiply"<<endl;
		cout<<"4. Divide"<<endl;
	    cout<<"5. Undo"<<endl;
		cout<<"6. Show History"<<endl;
		cout<<"7. Sort Results"<<endl;
		cout<<"Enter choice: "<<endl;
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            undoStack.push(result);

            string op;
            if (choice == 1) {
			 result = num1 + num2; op = "Add";
			  }
            else if (choice == 2) {
			 result = num1 - num2; op = "Subtract";
			  }
            else if (choice == 3) { 
			result = num1 * num2; op = "Multiply";
			 }
            else if (choice == 4) {
                if (num2 == 0) {
                    cout << "Error: Division by 0"<<endl;
                    undoStack.pop();
                    continue;
                }
                result = num1 / num2;
                op = "Divide";
            }

            history.add(op, result);
            cout << "Result = " << result << endl;
        }
        else if (choice == 5) {
            if (!undoStack.empty()) {
            	
                result = undoStack.top(); undoStack.pop();
                cout << "Undo successful. result: " << result << endl;
            } else {
                cout << "Nothing to undo."<<endl;
            }
        }
        else if (choice == 6) {
            cout << "Operation history:"<<endl;
            history.display();
        }
        else if (choice == 7) {
            int arr[100], size;
            history.extractResults(arr, size);
            bubbleSort(arr, size);
            cout << "Sorted results:";
            for (int i = 0; i < size; i++) cout << arr[i] << " ";
            cout << endl;
        }
        else {
            cout << "Invalid choice."<<endl;
        }

        cout << "Continue? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    cout << "Final Result: " << result << endl;
    return 0;
}
