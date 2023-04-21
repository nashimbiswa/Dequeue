#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
        prev=nullptr;
    }
};

struct Queue
{
    Node* front;
    Node *rear;
    int size;
    Queue()
    {
        front=nullptr;
        rear=nullptr;
        size=0;
    }

    void queueRear()
    {
        int data;
        cout<<"Enter the data in the Queue:\n";
        cin>>data;
        Node *newnode=new Node(data);
        if(!rear)
        {
            front=rear=newnode;
            ++size;
            
        }
        else
        {
            newnode->prev=rear;
            rear->next=newnode;
            rear=rear->next;
            ++size;
        }
    }

    void dqueueFront()
    {
        if(!front)
        {   
            cout<<"Queue is empty.\n";
            return;
        }
        int data=front->data;
        Node *temp=front;
        front=front->next;
        if(front==nullptr)
            rear=nullptr;
        else 
            front->prev=nullptr;
        --size;
        cout<<"Successfully deleted "<<data<<".\n";
    }

    void queueFront()
    {
        int data;
        cout<<"Enter the data in the Queue:\n";
        cin>>data;
        Node *newnode=new Node(data);
        if(!front)
        {
            front=rear=newnode;
            ++size;
        }
        else
        {
            
            front->prev=newnode;
            newnode->next=front;
            front=newnode;
            ++size;
        }
    }

    void deQueueRear()
    {   
        if(!rear)
        {   
            cout<<"Queue is empty.\n";
            return;
        }
        int data=rear->data;
        Node *temp=rear;
        rear=rear->prev;
        if(rear==nullptr)
            front=nullptr;
        else 
            rear->next=nullptr;
        --size;
        cout<<"Successfully deleted "<<data<<".\n";
    }

    int getFront()
    {
        if(!front)
            return -1;
        return front->data;
    }

    int getRear()
    {
        if(!rear)
            return -1;
        return rear->data;
    }
    int getSize()
    {
        return size;
    }

    void display()
    {
        if(!front)
        {
            cout<<"List is empty.\n";
            return;
        }
        Node *temp=front;
        cout<<"Values in the Queue are:\n";
        while (temp!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main(int argc, char const *argv[])
{
    Queue q1;
    int choice,val,dat,da;
    bool res1,res2;
    do
    {
        
        cout<<"\n1. To enqueue front.\n";
        cout<<"2. To enqueue rear.\n";
        cout<<"3.To Display.\n";
        cout<<"4. Get Size.\n";
        cout<<"5. To dequeue front.\n";
        cout<<"6. To get front.\n";
        cout<<"7. To get rear.\n";
        cout<<"8. To dequeue rear.\n";
        cout<<"9. To Exit.\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice)
        {
            case 1:
                q1.queueFront();
                break;
            case 2:
                q1.queueRear();
                break;
            case 3:
                q1.display();
                break;
            case 4:
                cout<<"Size of the Queue is "<< q1.getSize()<<".\n";
                break;
            case 5:
                q1.dqueueFront();
                break;
            case 6:
                cout<<"Front element is "<<q1.getFront()<<"\n";
                break;
            case 7:
                cout<<"Rear element is "<<q1.getRear()<<"\n";
                break;
            case 8:
                q1.deQueueRear();
                break;
        }
        if(choice==9)
            return 0;
    }while(true);
}