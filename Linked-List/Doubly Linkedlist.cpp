#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next=nullptr;
        prev=nullptr;
    }
};

class DoublyLinkedlist{
    private:
     Node* head;

    public:
        DoublyLinkedlist(){
            head=nullptr;
            }
    void traversal(){
        Node* temp=head;
        while(temp!=nullptr){
           cout<<temp->data<<" ";
           temp=temp->next;
        }
    }

    void searchimg(int key){
        Node* temp=head;
        while(temp!=nullptr && temp->data!=key){
           temp=temp->next;
        }
        if(temp->data==key){
            cout<<"Key is found";
            return;
        }
        cout<<"Key is not found";
        return;
    }

    void insertion(int val, int pos){
        if(pos<1){
            cout<<"Invalid position ";
            return;
        }
        Node* newNode=new Node(val);
        if(pos==1){
            newNode->next=head;
            if(head!=nullptr){
                newNode->next->prev=newNode;
            }
            head=newNode;
            return;
        }
        int count=1;
        Node* temp=head;
        while(count<pos-1 && temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<"Position is not of reach";
            return;
        }
        newnode->next=temp->next;
        if(temp->next1=nullptr){
        temp->next->prev=newnode;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }

};


