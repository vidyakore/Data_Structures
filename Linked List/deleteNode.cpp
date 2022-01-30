#include<iostream>
using namespace std;
class Node{
    public:

    Node* next;
    int data;
};

void addnode(int d,Node* head){
    Node *newnode = NULL;
    newnode = new Node();
    newnode->data = d;
    while(head->next!= NULL){
        head = head->next;
    }
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

void deleteEnd(Node* head)
{
    while(head->next->next!=NULL)
    {
        head = head->next;
    }
    head->next = NULL;
}

void deleteByIndex(int pos,Node* head)
{
    for (int i = 1; i < pos - 1;i++)
    {
        head = head->next;
    }
    head->next = head->next->next;
}

void deleteHead(Node*&head)
{
    head = head->next;
}
int main()
{
     Node* head = NULL;
    head = new Node();
    head->next = NULL;
    head->data = 0;
    addnode(1, head);
    addnode(2, head);
    addnode(3, head);
    display(head);
    deleteEnd(head);
    display(head);
    deleteByIndex(2, head);
    display(head);
    deleteHead(head);
    display(head);
}