#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void addtohead(node* &head,int val)
{
    node* temp=head;
    node* n=new node(val);
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    n->next=head;
    temp->next=n;
    head=n;
}

void addtopos(node* &head,int val,int pos)
{
    if(pos==1)
    {
        addtohead(head,val);
        return;
    }
    else
    {
        node* n=new node(val);
        node* temp=head;
        while(pos!=2)
        {
            temp=temp->next;
            pos--;
        }
        n->next=temp->next;
        temp->next=n;
        return;
    }
}

void addtotail(node* &head,int val)
{
    if(head==NULL)
    {
        addtohead(head,val);
        return;
    }
    node* temp=head;
    node* n=new node(val);
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;   
}

void deletenode(node* &head,int pos)
{
    node* temp=head;
    if(pos==1)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }

        node* todelete=head;   
        temp->next=head->next;
        head=head->next;

        delete todelete;
        return;
    }
    else
    {
        while(pos!=2)
        {
            temp=temp->next;
            pos--;
        }
        node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }
}

void display(node* &head)
{
    node* temp=head;
    cout<<"The nodes in circular linked list are: "<<endl;
    do
    {
        cout<<temp->data<<" "<<temp->next<<endl;
        temp=temp->next;
    } 
    while (temp!=head);
    
}

int main()
{
    node* head=NULL;
    addtotail(head,2);
    addtotail(head,3);
    addtotail(head,4);

    addtohead(head,1);

    deletenode(head,3);
    addtopos(head,3,3);

    display(head);
}