#include <iostream>
using namespace std;
int main()
{
    // 1
    // 21
    // 321
    // 4321
    // 54321

    int row;
    cout << "Enter no. of rows:";
    cin >> row;
    int i = 1;

    while (i <= row)
    {
        int a = i;
        int j = 1;
        while (j <= i)
        {
            cout << a;
            j++;
            a--;
        }
        cout << endl;
        i++;
    }
}