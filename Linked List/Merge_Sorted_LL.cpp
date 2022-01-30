#include<iostream>
using namespace std;
class node
{
    public:
        node *next;
        int data;
};


void addnode(int d,node* head)
{
    node *newnode = NULL;
    newnode = new node();
    newnode->data = d;
    while(head->next!= NULL)
    {
        head = head->next;
    }
    head->next = newnode;
}

void display(node* head)
{
    
    while (head!=NULL)
    {
        cout <<head->data<<"->";
        head = head->next;
    }
    
}

node* merge_LL(node* &h1,node* &h2)
{
    node *p1 = h1;
    node *p2 = h2;
    node *dummyNode = new node();
    node *temp = dummyNode;
    while (p1!=NULL && p2!=NULL)
    {
        if(p1->data < p2->data)
        {
            temp->next = p1;
            p1 = p1->next;
        }
        if(p2->data < p1->data)
        {
            temp->next = p2;
            p2 = p2->next;
        }
        temp = temp->next;
    }

    while(p1!=NULL)
    {
        temp->next = p1;
        p1 = p1->next;
        temp = temp->next;
    }
    
    while(p2!=NULL)
    {
        temp->next = p2;
        p2 = p2->next;
        temp = temp->next;
    }

    return dummyNode->next;
}

node* mergeRecursive(node* &h1,node* &h2)
{
    if(h1==NULL)
    {
        return h2;
    }
    if(h2==NULL)
    {
        return h1;
    }
    node *result;
    if(h1->data<h2->data)
    {
        result = h1;
        result->next = mergeRecursive(h1->next, h2);

    }
    else{
        result = h2;
        result->next = mergeRecursive(h1, h2-> next);
    }

    return result;
}

int main(){
    node *h1 = new node();
    h1->data = 1;
    h1->next = NULL;
    node *h2 = new node();
    h2->data = 2;
    h2->next = NULL;
    addnode(3, h1);
    addnode(5, h1);
    addnode(7, h1);

    addnode(4, h2);
    addnode(8, h2);
    addnode(9, h2);

    cout << "first linked list: \n";
    display(h1);
    cout << "\nsecond liked list:\n";
    display(h2);

    node *result = new node();
    cout << "\nmerged list: \n";
    result = mergeRecursive(h1, h2);
    cout << "\nmerged list: \n";
    display(result);
}
