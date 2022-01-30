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

void reverse(Node*& head)
{
    Node *prev, *current,*next;
    current = head;
    prev = NULL;
    while (current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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
    addnode(4, head);
    addnode(5, head);
    cout << "Before Reversing:\n";
    display(head);
    reverse(head);
    cout << "After Reversing:\n";
    display(head); 
}