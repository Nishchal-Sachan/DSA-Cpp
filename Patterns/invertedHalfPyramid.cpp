#include <iostream>
using namespace std;
int main()
{
    // ****
    // ***
    // **
    // *
    int row;
    cout << "Enter no. of rows:";
    cin >> row;
    int i = 1;

    while (i <= row)
    {
        int j = 1;
        while (j <= row - i + 1)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
