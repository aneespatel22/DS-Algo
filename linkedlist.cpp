#include<iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};

node *createnode(int a)
{
    node *newnode;
    newnode=(node *)malloc(sizeof(struct node));
    newnode->data=a;
    newnode->link=NULL;
    return newnode;
}

int main()
{
    int a;

    node *head;
    head=(node *)malloc(sizeof(struct node));
    head->data=10;
    head->link=NULL;

    node *current;
    current=(node *)malloc(sizeof(struct node));
    current->data=20;
    current->link=NULL;
    head->link=current;

    //Testing create function
    node *current2;
    current2=createnode(30);
    current->link=current2;

    node *current3;
    current3=createnode(40);
    current2->link=current3;

    cout<<"Data at First Node is: "<<head->data<<endl;
    cout<<"Link at First Node is: "<<head->link<<endl;

    cout<<"Data at Second Node is: "<<current->data<<endl;
    cout<<"Link at Second Node is: "<<current->link<<endl;

    cout<<"Data at Third Node is: "<<current2->data<<endl;
    cout<<"Link at Third Node is: "<<current2->link<<endl;   

    cout<<"Data at Fourth Node is: "<<current3->data<<endl;
    cout<<"Link at Fourth Node is: "<<current3->link<<endl;

    return 0;
}