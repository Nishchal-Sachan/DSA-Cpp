#include <iostream>
using namespace std;

int main()
{
    // AAAAA
    // BBBBB
    // CCCCC
    // DDDDD
    // EEEEE
    int row;
    cout << "Enter no. of rows:";
    cin >> row;
    int i = 1;
    char a = 'A';

    while (i <= row)
    {
        int j = 1;
        while (j <= row)
        {
            cout << a << " ";
            j++;
        }
        cout << endl;
        i++;
        a++;
    }
    return 0;
}
