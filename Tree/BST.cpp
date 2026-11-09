
// Binary Search Tree implementation in C++
#include <iostream>
using namespace std;

struct node {
    node *l, *r;
    int d;
};

class BST {
    node *root;

public:
    BST() {
        root = NULL;
    }

    void insert(int x);
    void traverse();
    void pre_order(node *t2);
    void post_order(node *t2);
    void in_order(node *t2);
    void delete_val();
    node* delete_e(int v, node *t);
};

// Insert a node
void BST::insert(int x) {
    node *nn = new node;

    nn->l = NULL;
    nn->r = NULL;
    nn->d = x;

    if (root == NULL) {
        root = nn;
    }
    else {
        node *t = root;
        node *prev = NULL;

        while (t != NULL) {
            prev = t;

            if (x > t->d) {
                t = t->r;
            }
            else if (x < t->d) {
                t = t->l;
            }
            else {
                cout << "Duplicate element not allowed";
                delete nn;
                return;
            }
        }

        if (x > prev->d) {
            prev->r = nn;
        }
        else {
            prev->l = nn;
        }
    }
}

// Display all traversals
void BST::traverse() {
    cout << "\nPreorder: ";
    pre_order(root);

    cout << "\nPostorder: ";
    post_order(root);

    cout << "\nInorder: ";
    in_order(root);
}

// Preorder traversal
void BST::pre_order(node *t2) {
    if (t2 != NULL) {
        cout << t2->d << " ";
        pre_order(t2->l);
        pre_order(t2->r);
    }
}

// Postorder traversal
void BST::post_order(node *t2) {
    if (t2 != NULL) {
        post_order(t2->l);
        post_order(t2->r);
        cout << t2->d << " ";
    }
}

// Inorder traversal
void BST::in_order(node *t2) {
    if (t2 != NULL) {
        in_order(t2->l);
        cout << t2->d << " ";
        in_order(t2->r);
    }
}

// Delete a value
void BST::delete_val() {
    int v;

    cout << "\nEnter value to delete: ";
    cin >> v;

    root = delete_e(v, root);
}

// Delete node from BST
node* BST::delete_e(int v, node *t) {

    if (t == NULL) {
        cout << "Element not found";
        return NULL;
    }

    if (v < t->d) {
        t->l = delete_e(v, t->l);
    }
    else if (v > t->d) {
        t->r = delete_e(v, t->r);
    }
    else {

        // Case 1: Leaf node
        if (t->l == NULL && t->r == NULL) {
            delete t;
            return NULL;
        }

        // Case 2: Only right child
        else if (t->l == NULL) {
            node *temp = t->r;
            delete t;
            return temp;
        }

        // Case 3: Only left child
        else if (t->r == NULL) {
            node *temp = t->l;
            delete t;
            return temp;
        }

        // Case 4: Two children
        else {
            node *temp = t->r;

            while (temp->l != NULL) {
                temp = temp->l;
            }

            t->d = temp->d;
            t->r = delete_e(temp->d, t->r);
        }
    }

    return t;
}

// Main function
int main() {
    BST b;
    int choice, x;
    char c;

    do {
        cout << "\n\n1. Insert";
        cout << "\n2. Traverse";
        cout << "\n3. Delete";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter element: ";
                cin >> x;
                b.insert(x);
                break;

            case 2:
                b.traverse();
                break;

            case 3:
                b.delete_val();
                break;

            case 4:
                cout << "Exiting program";
                return 0;

            default:
                cout << "Invalid choice";
        }

        cout << "\nDo you want to continue (y/n): ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}