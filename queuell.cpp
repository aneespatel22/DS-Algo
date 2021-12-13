#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* link;
    node(int val)
    {
        data=val;
        link=NULL;
    }
};

node* createnode(int val)
{
    node* newnode=new node(val);
    return newnode;
}
class queue
{
    public:
    node* front;
    node* back;
    node* temp;
    queue()
    {
        front=NULL;
        back=NULL;
        temp=NULL;
    }

    bool isempty()
    {
        if(front==NULL && back==NULL)
            return true;
        return false;
    }

    void push(node* n)
    {
        if(isempty())
        {
            front=back=n;
            cout<<"Node pushed"<<endl;
            return;
        }
        back->link=n;
        back=n;
        cout<<"Node pushed"<<endl;
    }

    void pop()
    {
        if(isempty())
        {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        temp=front;
        front=front->link;
        delete temp;
        cout<<"Node has been popped"<<endl;
    }

    void peek()
    {
        if(isempty())
        {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        cout<<front->data<<endl;
    }

    void display()
    {
        if(isempty())
        {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" "<<temp->link<<endl;
            temp=temp->link;
        }
    }
};

int main()
{
    queue q;

    node* firstnode=createnode(10);
    q.push(firstnode);

    node* secondnode=createnode(20);
    q.push(secondnode);

    node* thirdnode=createnode(30);
    q.push(thirdnode);

    node* fourthnode=createnode(40);
    q.push(fourthnode);

    node* fifthnode=createnode(50);
    q.push(fifthnode);

    q.pop();

    q.display();
}