#include <iostream>

using namespace std;

void binarySearch(int arr[], int n, int target)
{
    if (n <= 0)
    {
        cout << "Invalid Array size" << endl;
        return;
    }

    int low = 0, high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            cout << "\n"
                 << target << " found at index " << mid << endl;
            return;
        }

        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "\n"
         << target << " not found" << endl;
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

    binarySearch(arr, n, val);

    cout << "\nName: Pushkar Bansal" << endl;
    cout << "URN: 2514151" << endl;
    return 0;
}