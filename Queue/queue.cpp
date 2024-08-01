#include <bits/stdc++.h>
using namespace std;

// Queue implementation using circular array. < FIFO >

class MyQueue
{

private:
    int arr[30];
    int front;
    int rear;
    int cnt;
    int max_size = 30;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
        cnt = 0;
    }

    void push(int);
    int pop();
    bool isEmpty();
    int frontEle();
    int length();
    void print();
};

void MyQueue ::push(int data)
{
    if (cnt == max_size)
    {
        cout << "Queue is full" << endl;
        return;
    }
    arr[rear % max_size] = data;
    rear = (rear + 1) % max_size;
    cnt++;
}

int MyQueue ::pop()
{
    if (front == rear || cnt == 0)
    {
        return -1;
    }
    int data = arr[front % max_size];
    front = (front + 1) % max_size;
    cnt--;
    return data;
}

bool MyQueue ::isEmpty()
{
    return cnt == 0;
}

int MyQueue::frontEle()
{
    if (cnt == 0)
    {
        return -1;
    }

    return arr[front % max_size];
}

int MyQueue ::length()
{
    return cnt;
}

void MyQueue::print()
{
    if (cnt == 0)
    {
        cout << "Empty Queue" << endl;
        return;
    }

    for (int i = 0; i < cnt; i++)
    {
        cout << arr[(i + front) % max_size] << " ";
    }
}

int main()
{

    MyQueue q1;
    q1.push(20);
    q1.push(40);
    q1.push(60);
    q1.push(80);
    q1.push(100);

    q1.pop();

    int length = q1.length();
    int frontEle = q1.frontEle();
    bool isEmpty = q1.isEmpty();

    q1.print();

    cout << endl
         << "Length is: " << length << endl
         << "Front element: " << frontEle << endl
         << "isEmpty: " << isEmpty << endl;

    return 0;
}
