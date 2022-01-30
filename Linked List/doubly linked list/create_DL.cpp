#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node* next;
        node* prev;
};

void addnode(int d,node* head)
{
    node *newnode = NULL;
    newnode = new node();
    newnode->data = d;
    while (head->next!=NULL)
    {
        head = head->next;
    }
    head->next = newnode;
    newnode->prev = head;
}

void display(node* head)
{
    
    while (head!=NULL)
    {
        cout << "head data: "<<head->data<<endl;
        // cout << "head prev: "<<head->prev<<endl;
       
        head = head->next;
    }
    
}
int main()
{
    node* head = NULL;
    head = new node();
     head->prev = NULL;
    head->next = NULL;
    head->data = 4;
   
    addnode(1,head);
    addnode(2, head);
    addnode(3, head);
    addnode(4, head);
    addnode(5, head);
    display(head);
} 
