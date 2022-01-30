#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};
void CreateList(int d,Node* head)
{
    Node *newnode = NULL;
    newnode = new Node();
    newnode->data = d;
    if (head->next == 0)
    {
        head->data = d;
    }
    else{
      while (head->next!=NULL)
        {
           head = head->next;
        }
        head->next = newnode;  
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
    
void FindMid(Node* head)
{
    Node* temp = NULL;
    temp = new Node();
    temp = head;
    int count=0,j=0;
    while(temp->next!=NULL)
    {
        temp = temp->next;
        count++;
    }
    while(j<int(count)/2)
    {
        head = head->next;
        j++;
    }
    cout<<"mid is:"<<head->data;
    
}
int main()
{
    int n,ele,i=0;
    // cout << "Enter no of elements in List: ";
    // cin >> n;
    Node *head = NULL;
    head = new Node();
    // while (i<n)
    // {
    //     cin >> ele;
    //     CreateList(ele,head);
    //     i++;
    // }
    CreateList(1, head);
    CreateList(3, head);
    CreateList(5, head);
    CreateList(4, head);
    CreateList(2, head);
    CreateList(8, head);
    display(head);
    FindMid(head);
}