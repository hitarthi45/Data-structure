#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void traverse() {
        if (head == nullptr) {
            cout << "LinkedList is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "LinkedList: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Element " << key << " found in the LinkedList." << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "Element " << key << " not found in the LinkedList." << endl;
        return false;
    }

    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << "Element " << key << " deleted from the LinkedList." << endl;
            return;
        }

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Element " << key << " not found in the LinkedList." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Element " << key << " deleted from the LinkedList." << endl;
    }
};

void menu() {
    LinkedList LL;
    int choice, value;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Traverse" << endl;
        cout << "2. Search" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                LL.traverse();
                break;

            case 2:
                cout << "Enter the element to search: ";
                cin >> value;
                LL.search(value);
                break;

            case 3:
                cout << "Enter the element to insert: ";
                cin >> value;
                LL.insert(value);
                cout << "Element " << value << " inserted into the LinkedList." << endl;
                break;

            case 4:
                cout << "Enter the element to delete: ";
                cin >> value;
                LL.deleteNode(value);
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
