#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int usn;
    string name;
    int sem;
    string phone_no;
    Node *next;
};

Node *createNode(int usn, string n, int s, string phone)
{
    Node *newnode = new Node;
    newnode->name = n;
    newnode->usn = usn;
    newnode->sem = s;
    newnode->phone_no = phone;
    newnode->next = nullptr;

    return newnode;
}

Node *insertAtBeginning(Node *head, int usn, string n, int s, string phone)
{
    Node *newnode = createNode(usn, n, s, phone);
    newnode->next = head;
    head = newnode;
    cout << "\nStudent inserted at beginning successfully." << endl;
    return head;
}

void displayAndCount(Node *head)
{
    if (head == nullptr)
    {
        cout << "\nNo Student Data Present" << endl;
        return;
    }
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        cout << "\nStudent " << ++count << " Details:" << endl;
        cout << "USN: " << temp->usn << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Semester: " << temp->sem << endl;
        cout << "Phone No: " << temp->phone_no << endl;
        temp = temp->next;
    }

    cout << "\nTotal Students: " << count << endl;
}

Node *insertAtEnd(Node *head, int usn, string n, int s, string phone)
{
    if (head == nullptr)
    {
        head = insertAtBeginning(head, usn, n, s, phone);
        return head;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newnode = createNode(usn, n, s, phone);
    temp->next = newnode;
    cout << "\nStudent inserted at end successfully." << endl;
    return head;
}

Node *deleteAtBeginning(Node *head)
{
    if (head == nullptr)
    {
        cout << "\nNo Student Data Present" << endl;
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "\nFirst Student deleted successfully." << endl;
    return head;
}

Node *deleteAtEnd(Node *head)
{
    if (head == nullptr)
    {
        cout << "\nNo Student Data Present" << endl;
        return head;
    }

    if (head->next == nullptr)
    {
        delete head;
        cout << "\nLast Student deleted successfully." << endl;
        return nullptr;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    Node *extra = temp->next;
    temp->next = nullptr;
    delete extra;
    cout << "\nLast Student deleted successfully." << endl;
    return head;
}

Node *insertAtNth(Node *head, int usn, string n, int s, string phone)
{
    int pos;
    cout << "Enter the Position to insert: ";
    cin >> pos;

    if (pos <= 0)
    {
        cout << "Invalid Position" << endl;
        return head;
    }

    if (pos == 1 || head == nullptr)
    {
        return insertAtBeginning(head, usn, n, s, phone);
    }

    Node *temp = head;
    for (int i = 2; i < pos && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "\nInvalid Position" << endl;
        return head;
    }

    Node *newnode = createNode(usn, n, s, phone);
    newnode->next = temp->next;
    temp->next = newnode;
    cout << "\nStudent inserted at position " << pos << " successfully." << endl;
    return head;
}

Node *deleteAtNth(Node *head)
{
    int pos;
    cout << "Enter the Position to delete: ";
    cin >> pos;

    if (head == nullptr)
    {
        cout << "\nNo Student Data Present" << endl;
        return head;
    }

    if (pos <= 0)
    {
        cout << "\nInvalid Position" << endl;
        return head;
    }

    if (pos == 1)
    {
        return deleteAtBeginning(head);
    }

    Node *temp = head;
    for (int i = 2; i < pos && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "\nInvalid Position" << endl;
        return head;
    }

    Node *extra = temp->next;
    temp->next = temp->next->next;
    delete extra;
    cout << "\nStudent at position " << pos << " deleted successfully." << endl;
    return head;
}

void searchStudent(Node *head, int usn)
{
    int pos = 0;
    while (head)
    {
        if (head->usn == usn)
        {
            cout << "\nStudent with USN " << usn << " found at position " << ++pos << endl;
            return;
        };
        head = head->next;
    }
    cout << "\nStudent with USN " << usn << " not found!!!" << endl;
}

int main()
{
    Node *head = nullptr;
    int choice;

    do
    {
        cout << "\n\n----- STUDENT LINKED LIST MENU -----\n";
        cout << "1. Insert new student at beginning\n";
        cout << "2. Insert new student at end\n";
        cout << "3. Insert new student at nth position\n";
        cout << "4. Display all records and count nodes\n";
        cout << "5. Delete first student\n";
        cout << "6. Delete last student\n";
        cout << "7. Delete nth student\n";
        cout << "8. Search a student\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        int usn, sem;
        string name, phone;

        switch (choice)
        {

        case 1:
            cout << "\nEnter Student Details\n";

            cout << "Enter USN: ";
            cin >> usn;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Semester: ";
            cin >> sem;

            cout << "Enter Phone Number: ";
            cin >> phone;

            head = insertAtBeginning(head, usn, name, sem, phone);
            break;

        case 2:
            cout << "\nEnter Student Details\n";

            cout << "Enter USN: ";
            cin >> usn;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Semester: ";
            cin >> sem;

            cout << "Enter Phone Number: ";
            cin >> phone;

            head = insertAtEnd(head, usn, name, sem, phone);
            break;

        case 3:
            cout << "\nEnter Student Details\n";

            cout << "Enter USN: ";
            cin >> usn;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Semester: ";
            cin >> sem;

            cout << "Enter Phone Number: ";
            cin >> phone;

            head = insertAtNth(head, usn, name, sem, phone);
            break;

        case 4:
            displayAndCount(head);
            break;

        case 5:
            head = deleteAtBeginning(head);
            break;

        case 6:
            head = deleteAtEnd(head);
            break;

        case 7:
            head = deleteAtNth(head);
            break;

        case 8:
            int usn;
            cout << "Enter USN to search student: ";
            cin >> usn;
            searchStudent(head, usn);
            break;

        case 9:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 9);

    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    cout << "\nName: Pushkar Bansal " << endl;
    cout << "URN: 2514151" << endl;

    return 0;
}