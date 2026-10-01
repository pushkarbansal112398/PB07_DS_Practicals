#include <iostream>

using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0)
    {
        cout << "Invalid input entered" << endl;
        return 1;
    }

    int matrix1[rows][cols];

    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "]" << "[" << j << "] : ";
            cin >> matrix1[i][j];
        }
    }

    int matrix2[rows][cols];

    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "]" << "[" << j << "] : ";
            cin >> matrix2[i][j];
        }
    }

    int matrix3[rows][cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "\nResultant Matrix (Sum): " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix3[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "\nName: Pushkar Bansal" << endl;
    cout << "URN: 2514151" << endl;
    return 0;
}