#include <iostream>
using namespace std;

int main()
{
    //  1111
    //   222
    //    33
    //     4
    int row;
    cout << "Enter no. of rows:";
    cin >> row;
    int i = 1;
    int a = 1;
    while (i <= row)
    {
        int j = 0;
        while (j <= i - 1)
        {
            cout << " ";
            j++;
        }
        int k = 1;
        while (k <= row - i + 1)
        {
            cout << a;
            k++;
        }
        i++;
        a++;
        cout << endl;
    }
    return 0;
}
