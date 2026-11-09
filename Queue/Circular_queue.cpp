
// Circular Queue implementation in C++ using arrays
#include <iostream>
using namespace std;

#define MAX 4

class circular_queue
{
    int a[MAX], x, front, rear;

public:

    circular_queue()
    {
        front = -1;
        rear = -1;
    }

    void insert();
    void del();
    void display();
};

void circular_queue::insert()
{
    if ((rear + 1) % MAX == front)
    {
        cout << "\nQueue is full";
    }
    else
    {
        cout << "\nEnter element: ";
        cin >> x;

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        a[rear] = x;
    }
}

void circular_queue::del()
{
    if (front == -1)
    {
        cout << "\nQueue is empty";
    }
    else
    {
        x = a[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }

        cout << "\nDeleted: " << x;
    }
}

void circular_queue::display()
{
    if (front == -1)
    {
        cout << "\nQueue is empty";
    }
    else
    {
        int i = front;

        cout << "\nQueue elements: ";

        while (true)
        {
            cout << a[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }
    }
}

int main()
{
    circular_queue q;
    char c;
    int choice;

    do
    {
        cout << "\n1. Insert  2. Delete  3. Display";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                q.insert();
                break;

            case 2:
                q.del();
                break;

            case 3:
                q.display();
                break;

            default:
                cout << "\nInvalid choice";
        }

        cout << "\nYou want to continue? ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}