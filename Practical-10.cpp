#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createHead()
{
    Node *header = new Node;
    header->next = header;
    header->data = 0;
    return header;
}

Node *header = createHead();

Node *createNode(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(int val)
{
    Node *newNode = createNode(val);

    Node *prev = header;
    Node *temp = header->next;

    while (temp != header && temp->data < val)
    {
        prev = temp;
        temp = temp->next;
    }

    newNode->next = temp;
    prev->next = newNode;
    cout << "\n"
         << val << " inserted successfully" << endl;
}

void deleteNode(int val)
{
    if (header->next == header)
    {
        cout << "\nList is empty" << endl;
        return;
    }

    Node *prev = header;
    Node *temp = header->next;

    while (temp != header)
    {
        if (temp->data == val)
        {
            prev->next = temp->next;
            delete temp;
            cout << "\n"
                 << val << " deleted successfully" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "\n"
         << val << " not found in the List" << endl;
    return;
}

void display()
{
    if (header->next == header)
    {
        cout << "\nList is empty" << endl;
        return;
    }

    Node *temp = header->next;
    cout << "\nList: ";
    while (temp != header)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice, val;
    do
    {
        cout << "\n----- SORTED SCLL WITH HEADER NODE -----" << endl;
        ;
        cout << "1. Insert a value" << endl;
        cout << "2. Delete a value" << endl;
        cout << "3. Traverse the list" << endl;
        cout << "4. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter value to insert: ";
            cin >> val;
            insertNode(val);
            break;
        case 2:
            cout << "\nEnter value to delete: ";
            cin >> val;
            deleteNode(val);
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "\nExiting Program..." << endl;
            break;
        default:
            cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    Node *curr = header->next;
    while (curr != header)
    {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete header;

    cout << "\nName: Pushkar Bansal" << endl;
    cout << "URN: 2514151" << endl;

    return 0;
}