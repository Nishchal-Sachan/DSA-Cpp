#include <iostream>
using namespace std;

int main()
{
    // ABC
    // BCD
    // CDE
    int row;
    cout << "Enter no. of rows:";
    cin >> row;
    int i = 0;

    while (i < row)
    {
        char a = 'A' + i;
        int j = 1;
        while (j <= row)
        {
            cout << a;
            j++;
            a++;
        }
        cout << endl;
        i++;
    }
    return 0;
}