
// Simple Queue implementation in C++ using arrays
#include <iostream>
using namespace std;

#define MAX 4

class Queue
{
    int a[MAX], f, r, x;

public:
    Queue()
    {
        f = -1;
        r = -1;
    }

    void insert();
    void delete1();
    void display();
};

void Queue::insert()
{
    if (r == MAX - 1)
    {
        cout << "\nQueue Overflow";
    }
    else
    {
        cout << "\nEnter element: ";
        cin >> x;

        if (f == -1)
            f = 0;

        r++;
        a[r] = x;
    }
}

void Queue::delete1()
{
    if (f == -1)
    {
        cout << "\nQueue Underflow";
    }
    else
    {
        x = a[f];

        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f++;
        }

        cout << "\nDeleted item: " << x;
    }
}

void Queue::display()
{
    if (f == -1)
    {
        cout << "\nQueue has no element";
    }
    else
    {
        cout << "\nQueue elements are:\n";

        for (int i = f; i <= r; i++)
        {
            cout << a[i] << endl;
        }
    }
}

int main()
{
    Queue q;
    int choice;
    char c;

    do
    {
        cout << "\n1. Insert  2. Delete  3. Display";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                q.insert();
                break;

            case 2:
                q.delete1();
                break;

            case 3:
                q.display();
                break;

            default:
                cout << "\nInvalid choice";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}