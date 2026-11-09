
// Singly Linked List
#include <iostream>
using namespace std;

struct node
{
    int d;
    node *link;
};

class LL
{
    node *start;

public:

    void create();
    void display();
    void insert(int pos, int val);
    void count();
    void search();
    void delete_e();

    LL()
    {
        start = NULL;
    }

    ~LL()
    {
        node *t;
        while (start != NULL)
        {
            t = start;
            start = start->link;
            delete t;
        }
    }
};

// CREATE LINKED LIST

void LL::create()
{
    node *nn, *temp;
    char c;

    do
    {
        nn = new node;

        cout << "Enter data: ";
        cin >> nn->d;

        nn->link = NULL;

        if (start == NULL)
        {
            start = nn;
        }
        else
        {
            temp = start;

            while (temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = nn;
        }

        cout << "Want to add more data? (y/n): ";
        cin >> c;

    } while (c == 'y' || c == 'Y');
}

// INSERT ELEMENT AT A GIVEN POSITION

void LL::insert(int pos, int val)
{
    node *nn, *temp;

    nn = new node;
    nn->d = val;
    nn->link = NULL;

    if (pos < 1)
    {
        cout << "Invalid position";
        delete nn;
        return;
    }

    if (pos == 1)
    {
        nn->link = start;
        start = nn;
    }
    else
    {
        temp = start;
        int i = 1;

        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->link;
            i++;
        }

        if (temp == NULL)
        {
            cout << "Invalid position";
            delete nn;
            return;
        }

        nn->link = temp->link;
        temp->link = nn;
    }

    cout << "Element inserted";
}

// COUNT TOTAL ELEMENTS

void LL::count()
{
    int i = 0;
    node *temp;

    temp = start;

    if (start == NULL)
    {
        cout << "LL has no element";
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->link;
            i++;
        }

        cout << "Total elements: " << i;
    }
}

// SEARCH AN ELEMENT

void LL::search()
{
    node *t;
    int num, f = 0, i = 0;

    cout << "Enter element to search: ";
    cin >> num;

    t = start;

    while (t != NULL)
    {
        i++;

        if (t->d == num)
        {
            f = 1;
            cout << "Element found at position " << i;
            break;
        }
        else
        {
            t = t->link;
        }
    }

    if (f == 0)
    {
        cout << "Element not found";
    }
}

// DELETE AN ELEMENT

void LL::delete_e()
{
    node *t, *prev = NULL;
    int num;

    t = start;

    cout << "Enter element to delete: ";
    cin >> num;

    while (t != NULL)
    {
        if (t->d != num)
        {
            prev = t;
            t = t->link;
        }
        else
        {
            if (t == start)
            {
                start = t->link;
            }
            else
            {
                prev->link = t->link;
            }

            delete t;

            cout << "Element deleted";
            return;
        }
    }

    cout << "Data not found";
}

// DISPLAY LINKED LIST

void LL::display()
{
    node *t;

    t = start;

    if (start == NULL)
    {
        cout << "LL has no element";
        return;
    }

    cout << "Linked List: ";

    while (t != NULL)
    {
        cout << t->d << " ";
        t = t->link;
    }

    cout << endl;
}

// MAIN FUNCTION

int main()
{
    LL l;
    int choice, pos, val;

    do
    {
        cout << "\n\n----- LINKED LIST MENU -----";
        cout << "\n1. Create";
        cout << "\n2. Insert";
        cout << "\n3. Count";
        cout << "\n4. Search";
        cout << "\n5. Delete";
        cout << "\n6. Display";
        cout << "\n7. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                l.create();
                break;

            case 2:
                cout << "Enter position: ";
                cin >> pos;

                cout << "Enter value: ";
                cin >> val;

                l.insert(pos, val);
                break;

            case 3:
                l.count();
                break;

            case 4:
                l.search();
                break;

            case 5:
                l.delete_e();
                break;

            case 6:
                l.display();
                break;

            case 7:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 7);

    return 0;
}