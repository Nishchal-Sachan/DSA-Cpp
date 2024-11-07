#include <iostream>
using namespace std;

int main()
{
    // A
    // BB
    // CCC
    // DDDD
    int row;
    cout << "Enter no. of rows:";
    cin >> row;
    int i = 1;
    char a = 'A';

    while (i <= row)
    {
        int j = 1;
        while (j <= i)
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
