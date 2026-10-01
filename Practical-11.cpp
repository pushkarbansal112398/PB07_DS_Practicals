#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string SSN;
    string name;
    string dept;
    string designation;
    double sal;
    string phoneNo;
    Node *next;
    Node *prev;
};

Node *head = nullptr;
Node *tail = nullptr;

Node *createNode()
{
    Node *newNode = new Node();

    cout << "Enter SSN: ";
    cin >> newNode->SSN;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newNode->name);
    cout << "Enter Department: ";
    getline(cin, newNode->dept);
    cout << "Enter Designation: ";
    getline(cin, newNode->designation);
    cout << "Enter Salary: ";
    cin >> newNode->sal;
    cout << "Enter Phone Number: ";
    cin >> newNode->phoneNo;

    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

void insertAtBeginning()
{
    Node *newnode = createNode();
    newnode->next = head;
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        head->prev = newnode;
        head = newnode;
    }
    cout << "\nEmployee inserted at beginning" << endl;
}

void insertAtEnd()
{
    Node *newnode = createNode();
    newnode->prev = tail;
    if (tail == nullptr)
    {
        tail = newnode;
        head = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
    cout << "\nEmployee inserted at end" << endl;
}

void deleteAtBeginning()
{
    if (head == nullptr)
    {
        cout << "\nNo Employee to delete" << endl;
        return;
    }

    Node *temp = head;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    cout << "\nEmployee deleted at beginning" << endl;
}

void deleteAtEnd()
{
    if (tail == nullptr)
    {
        cout << "\nNo Employee to delete" << endl;
        return;
    }

    Node *temp = tail;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }

    cout << "\nEmployee deleted at end" << endl;
    delete temp;
}

void insertAtNth()
{
    int pos;
    cout << "Enter Position to insert element: ";
    cin >> pos;

    if (pos <= 0)
    {
        cout << "\nInvalid Position" << endl;
        return;
    }
    if (pos == 1 || head == nullptr)
    {
        insertAtBeginning();
        return;
    }

    Node *temp = head;
    for (int i = 2; i < pos; i++)
    {
        if (temp == nullptr)
        {
            cout << "\nInvalid Position" << endl;
            return;
        }
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "\nInvalid Position" << endl;
        return;
    }

    Node *newnode = createNode();
    newnode->prev = temp;
    newnode->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->prev = newnode;
    }
    else
    {
        tail = newnode;
    }

    temp->next = newnode;
    cout << "\nEmployee inserted at position " << pos << " successfully." << endl;
}

void deleteAtNth()
{
    if (head == nullptr)
    {
        cout << "\nNo Employee to delete" << endl;
        return;
    }
    int pos;
    cout << "Enter Position to delete element: ";
    cin >> pos;

    if (pos <= 0)
    {
        cout << "\nInvalid Position" << endl;
        return;
    }
    if (pos == 1)
    {
        deleteAtBeginning();
        return;
    }
    Node *temp = head;
    for (int i = 2; i <= pos; i++)
    {
        if (temp == nullptr)
        {
            cout << "\nInvalid Position" << endl;
            return;
        }
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "\nInvalid Position" << endl;
        return;
    }

    if (temp == tail)
    {
        deleteAtEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    cout << "\nEmployee at position " << pos << " deleted successfully." << endl;
}

void displayAndCount()
{
    Node *temp = head;
    int count = 0;
    if (head == nullptr)
    {
        cout << "\nNo Employee Data Present" << endl;
        return;
    }
    while (temp != nullptr)
    {
        cout << "\nEmployee " << ++count << " Details:" << endl;
        cout << "SSN: " << temp->SSN << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Department: " << temp->dept << endl;
        cout << "Designation: " << temp->designation << endl;
        cout << "Salary: " << temp->sal << endl;
        cout << "Phone No: " << temp->phoneNo << endl;
        temp = temp->next;
    }

    cout << "\nTotal number of employees: " << count << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n----- DOUBLY LINKED LIST -----\n";
        cout << "1. Insert Employee at Beginning\n";
        cout << "2. Insert Employee at End\n";
        cout << "3. Insert Employee at Nth Position\n";
        cout << "4. Display All Employees and Count\n";
        cout << "5. Delete Employee from Beginning\n";
        cout << "6. Delete Employee from End\n";
        cout << "7. Delete Nth Employee\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;

        case 2:
            insertAtEnd();
            break;

        case 3:
            insertAtNth();
            break;

        case 4:
            displayAndCount();
            break;

        case 5:
            deleteAtBeginning();
            break;

        case 6:
            deleteAtEnd();
            break;

        case 7:
            deleteAtNth();
            break;

        case 8:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 8);

    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;

    cout << "\nName: Pushkar Bansal" << endl;
    cout << "URN: 2514151" << endl;

    return 0;
}
