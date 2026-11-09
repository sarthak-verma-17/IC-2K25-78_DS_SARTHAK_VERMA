
// Doubly Linked List
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *p;
    node *n;
};

class dll
{
    node *start;

public:

    void create();
    void insert(int p, int d);
    void delete_e(int d);
    void display_rev();
    void list_rev();

    dll()
    {
        start = NULL;
    }

    ~dll()
    {
        node *temp;

        while (start != NULL)
        {
            temp = start;
            start = start->n;
            delete temp;
        }
    }
};

// CREATE DOUBLY LINKED LIST

void dll::create()
{
    char c;

    do
    {
        node *nn = new node;

        cout << "Enter data: ";
        cin >> nn->data;

        nn->n = NULL;
        nn->p = NULL;

        if (start == NULL)
        {
            start = nn;
        }
        else
        {
            node *temp = start;

            while (temp->n != NULL)
            {
                temp = temp->n;
            }

            temp->n = nn;
            nn->p = temp;
        }

        cout << "Continue? (y/n): ";
        cin >> c;

    } while (c == 'y' || c == 'Y');
}

// INSERT ELEMENT AT GIVEN POSITION

void dll::insert(int p, int d)
{
    node *nn = new node;

    nn->data = d;
    nn->p = NULL;
    nn->n = NULL;

    if (p < 1)
    {
        cout << "Invalid position";
        delete nn;
        return;
    }

    if (p == 1 || start == NULL)
    {
        nn->n = start;

        if (start != NULL)
        {
            start->p = nn;
        }

        start = nn;
    }
    else
    {
        int i = 1;
        node *temp = start;

        while (i < p - 1 && temp->n != NULL)
        {
            temp = temp->n;
            i++;
        }

        nn->n = temp->n;

        if (temp->n != NULL)
        {
            temp->n->p = nn;
        }

        temp->n = nn;
        nn->p = temp;
    }

    cout << "Element inserted";
}

// DELETE ELEMENT

void dll::delete_e(int d)
{
    node *temp = start;

    while (temp != NULL)
    {
        if (temp->data == d)
        {
            if (temp == start)
            {
                start = temp->n;

                if (start != NULL)
                {
                    start->p = NULL;
                }
            }
            else
            {
                temp->p->n = temp->n;

                if (temp->n != NULL)
                {
                    temp->n->p = temp->p;
                }
            }

            delete temp;

            cout << "Element deleted";
            return;
        }

        temp = temp->n;
    }

    cout << "Element not found";
}

// DISPLAY IN REVERSE ORDER

void dll::display_rev()
{
    node *temp = start;

    if (temp == NULL)
    {
        cout << "Empty list";
        return;
    }

    while (temp->n != NULL)
    {
        temp = temp->n;
    }

    cout << "DLL in reverse: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->p;
    }

    cout << endl;
}

// REVERSE DOUBLY LINKED LIST

void dll::list_rev()
{
    node *temp = NULL;
    node *current_node = start;

    while (current_node != NULL)
    {
        temp = current_node->p;

        current_node->p = current_node->n;
        current_node->n = temp;

        current_node = current_node->p;
    }

    if (temp != NULL)
    {
        start = temp->p;
    }

    cout << "List reversed successfully";
}

// MAIN FUNCTION

int main()
{
    dll l;

    int choice, pos, d;

    do
    {
        cout << "\n\n----- DOUBLY LINKED LIST -----";

        cout << "\n1. Create";
        cout << "\n2. Insert";
        cout << "\n3. Delete";
        cout << "\n4. Display Reverse";
        cout << "\n5. Reverse List";
        cout << "\n6. Exit";

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

                cout << "Enter data: ";
                cin >> d;

                l.insert(pos, d);
                break;

            case 3:
                cout << "Enter element to delete: ";
                cin >> d;

                l.delete_e(d);
                break;

            case 4:
                l.display_rev();
                break;

            case 5:
                l.list_rev();
                break;

            case 6:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 6);

    return 0;
}