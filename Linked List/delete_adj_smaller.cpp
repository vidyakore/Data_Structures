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


void deleteByIndex(int pos,Node* head)
{
    Node *temp = head;
    for (int i = 1; i < pos - 1;i++)
    {
        temp = temp->next;
    }
    cout << "deleted element is: " << temp->next->data << endl;
    temp->next = temp->next->next;
    
}


void deleteHead(Node*&head)
{
    head = head->next;
    cout << "head is deleted" << endl;
}

void del_fun(Node*head)
{
    Node* temp = head;
    int c = 1;
    while(temp->next!=NULL)
    {
        cout << "in function:\n";
        if(temp->data < temp->next->data)
        {
            cout << "bug"<<temp->data<<" "<<temp->next->data<<" \n";
            if(c==1)
            {
                deleteHead(head);
                cout << "in head\n";
                temp = head;
                cout << "temp = " << temp->data << endl;
                // c += 1;
                // continue;
            }
                
            else
            {
                cout << "for func: " << c << endl;
                deleteByIndex(c, head);
                cout << "c="<<c << endl;
                c -= 1;
            }
            
        }
        c += 1;
        temp = temp->next;
        cout << "head=" << head->data<<endl;
        cout << "c= " << c << endl;
    }

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

int main()
{
    Node* head = NULL;
    head = new Node();
    head->next = NULL;
    head->data = 1;
    addnode(2, head);
    addnode(5, head);
    addnode(4, head);
    addnode(9, head);
    addnode(7, head);
    // addnode(2, head);
    // addnode(1, head);
    // addnode(5, head);
    // addnode(9, head);

    display(head);
    del_fun(head);
    cout << "im out";
    display(head);
    
}