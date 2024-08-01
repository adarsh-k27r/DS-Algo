#include <bits/stdc++.h>
using namespace std;

// Stack implementation using array.

class MyStack
{

private:
    int arr[20];
    int top;

public:
    MyStack()
    {
        top = -1;
    }

    void push(int data)
    {
        arr[++top] = data;
    }

    int pop()
    {
        if (top == -1)
        {
            return -1;
        }

        top--;
        return arr[top + 1];
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int length()
    {
        return top + 1;
    }

    void print()
    {
        if (top == -1)
        {
            cout << "Empty stack" << endl;
        }
        for (int i = 0; i < top + 1; i++)
        {
            cout << arr[i] << " ";
        }
    }

    int topEle()
    {
        if (top == -1)
        {
            return -1;
        }
        return arr[top];
    }
};

int main()
{

    MyStack stack1;

    stack1.push(2);
    stack1.push(11);
    stack1.push(56);

    stack1.pop();
    stack1.print();

    int topElement = stack1.topEle();
    int length = stack1.length();
    bool isEmpty = stack1.empty();

    cout << endl
         << "Top Element: " << topElement << endl
         << "Length: " << length << endl
         << "isEmpty: " << isEmpty << endl;

    return 0;
}