#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* link;
};

node* createnode(int a)
{
    node* newnode;
    newnode=(node *)malloc(sizeof(struct node));
    newnode->data=a;
    newnode->link=NULL;
    return newnode;
}
void push(node* &head,int a)
{
    node* firstnode;
    firstnode=createnode(a);
    firstnode->link=head;
    head=firstnode;
}

void addtopos(node* &head,int a,int pos)
{
    node* ptr;
    ptr=head;
    node* newnode;
    newnode=(node *)malloc(sizeof(struct node));
    newnode->data=a;

    while(pos!=2)
    {
        ptr=ptr->link;
        pos--;
    }    

    newnode->link=ptr->link;
    ptr->link=newnode;
}

void addtotail(node* &head,int a)
{
    node* ptr;
    ptr=head;
    node* endnode;
    endnode=createnode(a);
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=endnode;
}

void deletenode(node **head,int pos)
{   
    node* current=*head;
    node* previous=*head;
    if(pos==1)
    {
        *head=current->link;
        free(current);
        current=NULL;
    }
    else
    {
        while(pos!=1)
        {
            previous=current;
            current=current->link;
            pos--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
}

void search(node* head,int a)
{
    node* ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==a)
        {
            cout<<a<<" is present in the list"<<endl;
            return;
        }
        ptr=ptr->link;
    }
    cout<<a<<" is not present in the list"<<endl;
    return;
}

int main()
{
    int a;
    int pos;
    node* ptr;

    node* head;
    head=createnode(2);

    node* second;
    second=createnode(4);
    head->link=second;

    //Adding to the begining of the list
    push(head,1);

    //Adding to certain postion, 3rd here
    addtopos(head,3,3);

    //Adding to end
    addtotail(head,5);

    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->link;
    }

    //Deleting the element
    cout<<"After deleting"<<endl;

    deletenode(&head,3);

    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->link;
    }

    //Searching element
    search(head,4);
}