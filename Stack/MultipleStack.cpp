
// Multiple Stack implementation in C++ using arrays
#include <iostream>
using namespace std;

#define MAX 4

class mst
{
    int a[MAX], top1, top2, x;

public:

    mst()
    {
        top1 = -1;
        top2 = MAX;
    }

    void push1();
    void push2();
    void pop1();
    void pop2();
    void show1();
    void show2();
};

void mst::push1()
{
    if (top1 + 1 == top2)
    {
        cout << "Stack Overflow";
    }
    else
    {
        cout << "Enter value: ";
        cin >> x;

        top1++;
        a[top1] = x;
    }
}

void mst::push2()
{
    if (top2 - 1 == top1)
    {
        cout << "Stack Overflow";
    }
    else
    {
        cout << "Enter value: ";
        cin >> x;

        top2--;
        a[top2] = x;
    }
}

void mst::pop1()
{
    if (top1 == -1)
    {
        cout << "Stack Underflow";
    }
    else
    {
        x = a[top1];
        top1--;

        cout << x << " Removed";
    }
}

void mst::pop2()
{
    if (top2 == MAX)
    {
        cout << "Stack Underflow";
    }
    else
    {
        x = a[top2];
        top2++;

        cout << x << " Removed";
    }
}

void mst::show1()
{
    if (top1 == -1)
    {
        cout << "Stack has no element";
    }
    else
    {
        for (int i = top1; i >= 0; i--)
        {
            cout << a[i] << endl;
        }
    }
}

void mst::show2()
{
    if (top2 == MAX)
    {
        cout << "Stack has no element";
    }
    else
    {
        for (int i = top2; i < MAX; i++)
        {
            cout << a[i] << endl;
        }
    }
}

int main()
{
    mst m;
    int choice;
    char c;

    do
    {
        cout << "\n1. Push1  2. Push2";
        cout << "\n3. Pop1   4. Pop2";
        cout << "\n5. Show1  6. Show2";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                m.push1();
                break;

            case 2:
                m.push2();
                break;

            case 3:
                m.pop1();
                break;

            case 4:
                m.pop2();
                break;

            case 5:
                m.show1();
                break;

            case 6:
                m.show2();
                break;

            default:
                cout << "Invalid choice";
        }

        cout << "\nYou want to continue? ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}