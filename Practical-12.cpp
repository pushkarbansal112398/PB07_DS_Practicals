#include <iostream>
using namespace std;

struct Term
{
    int coeff;
    int xPower, yPower, zPower;
    Term *next;

    Term(int c, int x, int y, int z)
    {
        coeff = c;
        xPower = x;
        yPower = y;
        zPower = z;
        next = nullptr;
    }
};

Term *insertTerm(Term *head, int coeff, int xPower, int yPower, int zPower)
{
    Term *newNode = new Term(coeff, xPower, yPower, zPower);

    if (!head)
        return newNode;

    Term *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

void printPoly(Term *head)
{
    Term *temp = head;

    while (temp != nullptr)
    {
        cout << temp->coeff << "x^" << temp->xPower
             << "y^" << temp->yPower
             << "z^" << temp->zPower;

        temp = temp->next;

        if (temp)
            cout << " + ";
    }

    cout << "\n";
}

Term *addPoly(Term *p1, Term *p2)
{
    Term *result = nullptr;

    while (p1 != nullptr && p2 != nullptr)
    {

        if (p1->xPower == p2->xPower &&
            p1->yPower == p2->yPower &&
            p1->zPower == p2->zPower)
        {
            int sum = p1->coeff + p2->coeff;

            result = insertTerm(result, sum, p1->xPower, p1->yPower, p1->zPower);

            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {

            result = insertTerm(result, p1->coeff, p1->xPower, p1->yPower, p1->zPower);

            p1 = p1->next;
        }
    }

    while (p1 != nullptr)
    {
        result = insertTerm(result, p1->coeff, p1->xPower, p1->yPower, p1->zPower);

        p1 = p1->next;
    }

    while (p2 != nullptr)
    {
        result = insertTerm(result, p2->coeff, p2->xPower, p2->yPower, p2->zPower);

        p2 = p2->next;
    }

    return result;
}

int main()
{
    Term *p1 = nullptr;

    p1 = insertTerm(p1, 5, 3, 2, 1);
    p1 = insertTerm(p1, 4, 2, 1, 2);
    p1 = insertTerm(p1, 2, 0, 0, 0);

    Term *p2 = nullptr;

    p2 = insertTerm(p2, 3, 3, 2, 1);
    p2 = insertTerm(p2, 6, 2, 1, 2);
    p2 = insertTerm(p2, 1, 0, 0, 0);

    cout << "\nPOLY1: ";
    printPoly(p1);

    cout << "\nPOLY2: ";
    printPoly(p2);

    Term *sum = addPoly(p1, p2);

    cout << "\nPOLYSUM: ";
    printPoly(sum);

    cout << "\nName: Pushkar Bansal" << endl;
    cout << "URN: 2514151" << endl;

    return 0;
}