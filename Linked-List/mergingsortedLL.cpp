#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
    Node(int val){
       data=val;
       next=nullptr;
       return;
    }
};

class SinglyLL{
    private:
        Node* head;
    public:
        SinglyLL(){
            head=nullptr;
        }
        void insert_at_end(int val){
         Node*newnode=new Node(val);
         if(head==nullptr){
            head=newnode;
            return;
         }


        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;

    }

    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;

        }
    }
    Node* gethead(){
            return head;
        }
    void merging(Node* list1, Node* list2){
        SinglyLL result;
        while(list1!=nullptr and list2!=nullptr){
            if(list1->data<list2->data){
                result.insert_at_end(list1->data);
                list1=list1->next;
            }
            else{

                result.insert_at_end(list2->data);
                list2=list2->next;
            }
        }
        while(list1!=nullptr){
                result.insert_at_end(list1->data);
                list1=list1->next;
        }
        while(list2!=nullptr){
                result.insert_at_end(list2->data);
                list2=list2->next;
        }
    }
};

int main()
{
    SinglyLL list1, list2;
    list1.insert_at_end(1);
    list1.insert_at_end(3);
    list1.insert_at_end(5);
    list1.insert_at_end(7);

    list2.insert_at_end(2);
    list2.insert_at_end(6);
    list2.insert_at_end(8);
    list2.insert_at_end(10);
    list2.insert_at_end(12);

    list1.display();
    cout<<"\n";
    list2.display();
    cout<<"Merging\n";
    list1.merging(list1.gethead(),list2.gethead());

    return 0;
}
