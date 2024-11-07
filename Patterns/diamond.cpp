#include <iostream>
using namespace std;

int main()
{
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    // *********
    //  *******
    //   *****
    //    ***
    //     *
    int n = 5;
    int i = 1;
    // Upper half
    while (i <= n)
    {
        int j = 1;
        while (j <= (n - i))
        {
            cout << " ";
            j++;
        }
        int k = 1;
        while (k <= (2 * i) - 1)
        {
            cout << "*";
            k++;
        }
        i++;
        cout << endl;
    }

    int a = n;
    while (a >= 1)
    {
        int j = 1;
        while (j <= (n - a))
        {
            cout << " ";
            j++;
        }
        int k = 1;
        while (k <= (2 * a) - 1)
        {
            cout << "*";
            k++;
        }
        a--;
        cout << endl;
    }
    return 0;
}
