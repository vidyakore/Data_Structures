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
        cout <<head->data<<"->";
        // cout << "head prev: "<<head->prev<<endl;
       
        head = head->next;
    }
    
}

void reverse_Dll(node*& head)
{
    node *cur = head;
    if(cur==NULL || cur->next==NULL)
    {
        return;
    }
    while(cur->next != NULL)
        cur = cur->next;
    head = cur;
    cur->next = cur->prev;
    cur->prev = NULL;
    cur = cur->next;
    while(cur->prev != NULL)
    {
        node *temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        cur = cur->next;
    }
    cur->prev = cur->next;
    cur->next = NULL;
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
    reverse_Dll(head);
    cout << "\nafter reversing: \n";
    display(head);
} 
