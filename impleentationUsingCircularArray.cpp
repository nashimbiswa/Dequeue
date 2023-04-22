#include<bits/stdc++.h>
using namespace std;

struct Dequeue
{
    int capacity,size,front;
    int *arr;
    Dequeue(int cap)
    {
        arr=new int[cap];
        capacity=cap;
        size=0;
        front=0;
    }

    bool isEmpty()
    {
        return size==0;
    }

    bool isFull()
    {
        return size==capacity;
    }

    int getFront()
    {
        if(isEmpty())
            return -1;
        return front;
    }

    int getRear()
    {
        if(isEmpty())
            return -1;
        else
        {
            return (front+size-1)%capacity;
        }
    }

    int getSize(){return size;}

    void rearEnqueue()
    {
        if(isFull())
            cout<<"Queue is full.\n";
        else
        {
            int data;
            cout<<"Enter the data to insert in the Queue:\n";
            cin>>data;
            int rear=getRear();
            rear=(front+size)%capacity;
            arr[rear]=data;
            ++size;
        }
    }

    void DequeueRear()
    {
        if(isEmpty())
            cout<<"Queue is empty.\n";
        else
        {
            int data=arr[getRear()];
            // option rear=(getRear()-1+capacity)%capacity;
            --size;
            cout<<"Deleted element is "<<data;
        }
    }

    void DeQueueFront()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty.\n";
        }
        else
        {
            int data=arr[front];
            front=(front+1)%capacity;
            --size;
            cout<<"Deleted element is "<<data<<".\n";
        }
    }

    void frontEnqueue()
    {
        if(isFull())
        {
            cout<<"Queeue is full.\n";
        }
        else
        {
            int data;
            cout<<"Enter the data you want to insert:\n";
            cin>>data;
            front=(front-1+capacity)%capacity;
            arr[front]=data;
            ++size;
        }
    }

};

int main(int argc, char const *argv[])
{
    int capacity;
    cout<<"Enter the capacity of a queue:\n";
    cin>>capacity;
    Dequeue q1(capacity);
    int choice,val,dat,da;
    do
    {
        
        cout<<"\n1.To enqueue front.\n";
        cout<<"2.To enqueue rear.\n";
        cout<<"3.Get Size.\n";
        cout<<"4.To dequeue front.\n";
        cout<<"5.To get front.\n";
        cout<<"6.To get rear.\n";
        cout<<"7.To dequeue rear.\n";
        cout<<"8.To check isEmpty.\n";
        cout<<"9.To check is Full.\n";
        cout<<"10.To Exit.\n";
        cout<<"Enter your choice:\n";
        cin>>choice;
        switch (choice)
        {
            case 1:
                q1.frontEnqueue();
                break;
            case 2:
                q1.rearEnqueue();
                break;
            case 3:
                cout<<"Size of the Queue is "<< q1.getSize()<<".\n";
                break;
            case 4:
                q1.DeQueueFront();
                break;
            case 5:
                val=q1.getFront();
                if(val==-1)
                {
                    cout<<"Queue is empty.\n";
                }
                else
                    cout<<"Front element is "<<q1.arr[val]<<"\n";
                break;
            case 6:
                val=q1.getRear();
                if(val==-1)
                {
                    cout<<"Queue is empty.\n";
                }
                cout<<"Rear element is "<<q1.arr[val]<<"\n";
                break;
            case 7:
                q1.DequeueRear();
                break;
            case 8:
                cout<<"The queue is "<<q1.isEmpty();
                break;
            case 9:
                cout<<"The queue is "<<q1.isFull();
                break;
        }
        if(choice==10)
            return 0;
    }while(true);
}