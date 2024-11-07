#include <iostream>
using namespace std;
int main()
{
    // *             *
    // * *         * *
    // * * *     * * *
    // * * * * * * * *
    // * * * * * * * *
    // * * *     * * *
    // * *         * *
    // *             *

    int n;
    cout << "Enter n: ";
    cin >> n;

    // 1st half
    for (int i = 1; i <= n; i++)
    {
        // stars-i
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        // spaces-2(n-i)
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << "  ";
        }

        // stars-i
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // 2nd half
    for (int i = n; i > 0; i--)
    {
        // stars-i
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        // spaces-2(n-i)
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << "  ";
        }

        // stars-i
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}