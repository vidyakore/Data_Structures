#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
};

// adding node at end
void addnode(int d,Node* head){
    Node* newnode = NULL;
    newnode = new Node();
    newnode->data = d;
    while(head->next!= NULL)
    {
        head = head->next;
    }
    head->next = newnode;
    newnode->next = NULL;
}

// adding node at start
void addAtStart(int d,Node*& head)
{
    Node* newnode = NULL;
    newnode = new Node();
    newnode->data = d;
    newnode->next = head;
    head = newnode;
}
// adding node by index
void addByIndex(int d,int pos,Node* head)
{
    Node *newnode = NULL;
    newnode = new Node();
    newnode->data = d;
    for(int i = 1;i<pos-1;i++)
    {
        head = head->next;
    }
    newnode->next = head->next;
    head->next = newnode;
}

void display(Node* head)
{
     while (head!=NULL)
    {
        cout << head->data<<"->";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    head = new Node();
    addnode(1, head);
    addnode(2, head);
    addnode(3, head);
    display(head);
    addAtStart(5, head);
    display(head);
    addByIndex(10, 2, head);
    display(head);
}