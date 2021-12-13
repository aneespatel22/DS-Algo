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

class stack
{
    public:
    node* top;
    stack()
    {
        top=NULL;
    }

    bool isempty()
    {
        if(top==NULL)
            return true;
        else
            return false;
    }

    void push(node* n)
    {
        if(isempty())
        {
            top=n;
            cout<<"Node pushed"<<endl;
            return;
        }
        node* temp=top;
        top=n;
        n->link=temp;
        cout<<"Node pushed"<<endl;
    }

    void pop()
    {
        if(isempty())
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        node* temp=top;
        top=top->link;
        delete temp;
        cout<<"Node has been popped"<<endl;
    }

    void display()
    {
        node* temp=top;
        cout<<"All the elements in Stack are: "<<endl;
        while(temp!=NULL)
        {
            cout<<temp->data<<" "<<temp->link<<endl;
            temp=temp->link;
        }
    }
};

int main()
{
    stack st;

    node* firstnode=createnode(10);
    st.push(firstnode);

    node* secondnode=createnode(20);
    st.push(secondnode);

    node* thirdnode=createnode(30);
    st.push(thirdnode);

    node* fourthnode=createnode(40);
    st.push(fourthnode);

    node* fifthnode=createnode(50);
    st.push(fifthnode);

    st.pop();

    st.display();
}