#include <iostream>
using namespace std;

int main()
{
    // ABC
    // DEF
    // GHI
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
            a++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
