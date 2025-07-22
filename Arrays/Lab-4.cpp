#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* mergeSortedLists(Node* list1, Node* list2) {

    Node dummy(0);
    Node* tail = &dummy;

    while (list1 && list2) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    insert(list1, 1);
    insert(list1, 3);
    insert(list1, 5);

    insert(list2, 2);
    insert(list2, 4);
    insert(list2, 6);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Node* mergedList = mergeSortedLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
