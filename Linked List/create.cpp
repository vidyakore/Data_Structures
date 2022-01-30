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
int main()
{
     Node* head = NULL;
    head = new Node();
    head->next = NULL;
    head->data = 0;
    addnode(1, head);
    addnode(2, head);
    addnode(3, head);
    while (head!=NULL)
    {
        cout << head->data<<" ";
        head = head->next;
    }
    
}