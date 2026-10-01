#include <iostream>

using namespace std;

void linearSearch(int arr[], int n, int val)
{
    if (n <= 0)
    {
        cout << "\nInvalid Size of Array" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            cout << "\n"
                 << val << " found at index " << i << endl;
            return;
        }
    }
    cout << "\n"
         << val << " not found in array" << endl;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int val;
    cout << "Enter the value you want to search: ";
    cin >> val;

    linearSearch(arr, n, val);

    cout << "\nName: Pushkar Bansal" << endl;
    cout << "URN: 2514151" << endl;

    return 0;
}