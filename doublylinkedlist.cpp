#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void addtohead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;

    if(head!=NULL)
        head->prev=n;
    head=n;
}

void addtopos(node* &head,int val,int pos)
{
    node* temp=head;
    if(pos==1)
    {
        addtohead(head,val);
        return;
    }

    else
    {
        node* n=new node(val);
        while(pos!=2)
        {
            temp=temp->next;
            pos--;
        }
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
        n->prev=temp;
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
    node* temp;
    node* n=new node(val);
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void deletenode(node* &head,int pos)
{
    node* temp=head;
    if(pos==1)
    {
        head=head->next;
        head->prev=NULL;
        delete temp;
        return;
    }   
    int count=1;
    while(temp!=NULL && pos!=1)
    {
        temp=temp->next;
        pos--;
    }
    temp->prev->next=temp->next;

    if(temp->next!=NULL)
    {
    temp->next->prev=temp->prev;
    }
    delete temp;
}

void display(node* head)
{
    node* temp;
    temp=head;
    cout<<"The nodes in doubly linked list are: "<<endl;
    while(temp!=NULL)
    {
        cout<<temp->prev<<" "<<temp->data<<" "<<temp->next<<endl;
        temp=temp->next;
    }

}

int main()
{
    node* head=NULL;
    addtohead(head,2);
    addtotail(head,4);
    addtohead(head,1);

    addtopos(head,3,3);
    deletenode(head,4);

    display(head);
}