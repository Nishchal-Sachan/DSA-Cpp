#include <iostream>
using namespace std;

int main()
{
    //       *
    //     * *
    //   * * *
    // * * * *
    int row;
    cout << "Enter no. of rows:";
    cin >> row;
    int i = 1;
    while (i <= row)
    {
        int j = 1;
        while (j <= row - i)
        {
            cout << "  ";
            j++;
        }
        int k = 1;
        while (k <= i)
        {
            cout << "* ";
            k++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
