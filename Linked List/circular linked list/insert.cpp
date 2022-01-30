#include<iostream>
using namespace std;
class Node{
    public:

    Node* next;
    int data;
};

void insertAtHead(int d,Node* &head)
{
    Node *n = new Node();
    n->data = d;
    n->next = NULL;

    if(head==NULL)
    {
        n->next = n;
    }
    Node *temp = head;

    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void addnode(int d,Node* &head){

    if(head==NULL)
    {
        insertAtHead(d,head);
        return;
    }
    Node *newnode = NULL;
    newnode = new Node();
    newnode->data = d;
    Node *temp = new Node();
    temp = head;

    while(temp->next!= head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

void display(Node* head)
{
    Node *temp = head;
    do
    {
        cout << temp->data<<"->";
        temp = temp->next;
    } while (temp!= head);
    
    
}

int main()
{
    Node* head = NULL;
    head = new Node();
    head->data = 5;
    head->next = NULL;
    addnode(1, head);
    addnode(2, head);
    addnode(3, head);
    addnode(4, head);
    display(head);
}