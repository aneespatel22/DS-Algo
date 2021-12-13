#include<iostream>
using namespace std;
#define n 5

class queue
{
    int *arr;
    int front;
    int back;
    public:
    queue()
    {
    front=-1; 
    back=-1;
    arr=new int[n];
    }

    void push(int x)
    {
        if(back==4)
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1)
        {
            front++;
        }
    }

    void pop()
    {
        if (isempty())
        {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (isempty())
        {
            cout<<"Queue Underflow"<<endl;
            return 1;
        }
        return arr[front];
    }

    bool isempty()
    {
        if (front==-1 || front>back)
        {
            return true;
        }
        return false;
    }

};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);


    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();
    
    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;    
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    //Queue should be empty
    cout<<"1=Empty 2=Not empty :"<<q.isempty();
}