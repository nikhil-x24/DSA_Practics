                                  /*
Enter the value of n: 5
*
*1*
*121*
*12321*
*1234321*
*123454321*
*1234321*
*12321*
*121*
*1*
*

                              */
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "*" << endl; 

    for (int i = 1; i <= n; i++)
    {
        cout << "*";
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        for (int k = i - 1; k >= 1; k--)
        {
            cout << k;
        }

        cout << "*" << endl;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        cout << "*";

        for (int k = 1; k <= n - i; k++)
        {
            cout << k;
        }

        for (int k = 1; k <= n - 1 - i; k++) // focus
        {
            cout << n - i - k;
        }

        cout << "*" << endl;
    }

    cout << "*"; // run only one time
    return 0;
}