#include <iostream>
using namespace std;

int main()
{
    // ABCD
    // ABCD
    // ABCD
    // ABCD
    int row;
    cout << "Enter no. of rows:";
    cin >> row;
    int i = 1;

    while (i <= row)
    {
        char a = 'A';
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
