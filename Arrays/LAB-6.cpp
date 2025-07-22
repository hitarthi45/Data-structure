#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;  // Pointer to the next node
    Node* prev;  // Pointer to the previous node

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insert_at_position(int value, int position) {

        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* new_node = new Node(value);

        // Insert at the beginning if position is 1
        if (position == 1) {
            if (head != nullptr) {
                new_node->next = head;
                head->prev = new_node;
            }
            head = new_node;
            return;
        }

        // Traverse the list to find the position
        Node* temp = head;
        int i=1;
        while(temp!=nullptr && i<position-1){
            temp=temp->next;
        }
        if (temp == nullptr) {
            cout << "Position is beyond the length of the list" << endl;
            return;
        }

        // Inserting in between or at the end
        new_node->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }

    // Function to delete a node with a given value
    void delete_node(int value) {
        Node* temp = head;

        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {  // Node with the given value was not found
            cout << "Node with value " << value << " not found!" << endl;
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {   //delete at begin
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Function to search for a node with a given value
    Node* search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;  // Node with the given value was not found
    }

    // Function to traverse the list and print its elements
    void traverse() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insert_at_position(10, 1);  // Insert at beginning
    dll.insert_at_position(20, 2);  // Insert at end
    dll.insert_at_position(15, 2);  // Insert in the middle

    cout << "List after insertions: ";
    dll.traverse();

    dll.delete_node(20);
    cout << "List after deleting 20: ";
    dll.traverse();

    Node* result = dll.search(15);
    if (result != nullptr) {
        cout << "Node with value 15 found!" << endl;
    } else {
        cout << "Node with value 15 not found!" << endl;
    }

    return 0;
}
