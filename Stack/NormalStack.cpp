
// Stack implementation in C++ using arrays
#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
    int arr[MAX], top;

public:

    Stack()
    {
        top = -1;
    }

    void push()
    {
        int n;

        if (top == MAX - 1)
        {
            cout << "Stack Overflow";
        }
        else
        {
            cout << "Enter the element to push: ";
            cin >> n;

            top++;
            arr[top] = n;

            cout << n << " pushed into stack";
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow";
        }
        else
        {
            int d = arr[top];
            top--;

            cout << "Item popped: " << d;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack has no elements";
        }
        else
        {
            cout << "Stack elements are:\n";

            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

void main()
{
    Stack s;
    int choice;
    char ch;

    do
    {
        cout << "\n1. Push  2. Pop  3. Display";
        cin >> choice;

        switch(choice)
        {
            case 1:
                s.push();
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;
        }

        cout << "\nDo you want to continue?";
        cin >> ch;

    } while(ch == 'y' || ch == 'Y');
}