#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};

void insertAtTail(Node* head,int d)
{
    Node *newnode = new Node();
    newnode->data = d;
    Node *temp = new Node();
    temp = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

void display(Node *head)
{
    Node *temp = new Node();
    temp = head;
    do
    {
        cout << temp->data;
        temp = temp->next;
    } while (temp!=head);
    
}
int main()
{
    Node *head = new Node();
    head->data = 10;
    head->next = NULL;
    insertAtTail(head, 11);
    insertAtTail(head, 12);
    insertAtTail(head, 13);
    insertAtTail(head, 14);
    display(head);
    return 0;
}
