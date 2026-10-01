#include <iostream>

using namespace std;

int main()
{
    int arr[100];
    int choice, pos, elem;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    do
    {
        cout << "\nMENU" << endl;
        cout << "1. Display Array elements" << endl;
        cout << "2. Add element at an index" << endl;
        cout << "3. Delete element at an index" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (n <= 0)
                cout << "\nArray is empty" << endl;
            else
            {
                cout << "\nArray: ";
                for (int i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;
        case 2:
            cout << "Enter the index position (0 to " << n << "): ";
            cin >> pos;

            if (pos < 0 || pos > n)
            {
                cout << "\nInvalid index position entered" << endl;
                break;
            }

            cout << "Enter element to add: ";
            cin >> elem;

            for (int i = n; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[pos] = elem;
            n++;

            cout << "\nElement added successfully" << endl;
            break;
        case 3:
            cout << "Enter the index position (0 to " << n - 1 << "): ";
            cin >> pos;

            if (pos < 0 || pos >= n)
            {
                cout << "\nInvalid index position entered" << endl;
                break;
            }

            for (int i = pos; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;

            cout << "\nElement deleted successfully" << endl;
            break;
        case 4:
            cout << "\nExiting..." << endl;
            break;
        default:
            cout << "\nInvalid choice entered" << endl;
        }
    } while (choice != 4);

    cout << "\nName: Pushkar Bansal" << endl;
    cout << "URN: 2514151" << endl;

    return 0;
}