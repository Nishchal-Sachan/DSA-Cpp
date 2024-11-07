#include <iostream>
using namespace std;
int main()
{
    // 1
    // 22
    // 333
    // 4444
    // 55555
    int row;
    cout << "Enter no. of rows:";
    cin >> row;
    int i = 1;
    int a = 1;
    while (i <= row)
    {
        int j = 1;
        while (j <= i)
        {
            cout << a << " ";
            j++;
        }
        cout << endl;
        a++;
        i++;
    }
}