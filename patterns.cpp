#include <bits/stdc++.h>
using namespace std;

// * * * * * *
// * * * * * *
// * * * * * *
// * * * * * *
// * * * * * *
// * * * * * *
void printPattern1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// *
// * *
// * * *
// * * * *
// * * * * *
// * * * * * *
void printPattern2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// 1 2 3 4 5 6
void printPattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

// 1
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5
// 6 6 6 6 6 6
void printPattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// * * * * * *
// * * * * *
// * * * *
// * * *
// * *
// *
void printPattern5(int n)
{
    // for (int i = n; i > 0; i--)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // OR

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// 1 2 3 4 5 6
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1
void printPattern6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

//           *
//         * * *
//       * * * * *
//     * * * * * * *
//   * * * * * * * * *
// * * * * * * * * * * *
void printPattern7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * (n - 1) + 1; j++)
        {
            if (j > (n - i) && j <= ((n - i) + 2 * (i - 1) + 1))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    // OR

    // for (int i = 1; i <= n; i++) {
    //     int stars = 2 * i - 1;
    //     int spaces = n - i;
    //     for (int j = 1; j <= spaces; j++) cout << "  ";
    //     for (int j = 1; j <= stars; j++) cout << "* ";
    //     cout << endl;
    // }

    // OR

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << "  ";
    //     }

    //     for (int j = 1; j <= 2 * i - 1; j++)
    //     {
    //         cout << "* ";
    //     }

    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << "  ";
    //     }
    //     cout << endl;
    // }
}

// ***********
//  *********
//   *******
//    *****
//     ***
//      *
void printPattern8(int n)
{

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i - 1; j++)
    //     {
    //         cout << "  ";
    //     }

    //     for (int j = 1; j <= 2 * (n - i) + 1; j++)
    //     {
    //         cout << "* ";
    //     }

    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << "  ";
    //     }
    //     cout << endl;
    // }

    // OR

    for (int i = 1; i <= n; i++)
    {
        int spaces = i - 1;
        int stars = 2 * (n - i) + 1;
        for (int j = 1; j <= spaces; j++)
            cout << "  ";

        for (int j = 1; j <= stars; j++)
            cout << "* ";

        cout << endl;
    }
}

// ******
// *    *
// *    *
// *    *
// *    *
// ******
void printPattern21(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int input_size;
    cin >> input_size;

    // printPattern1(input_size);
    // printPattern2(input_size);
    // printPattern3(input_size);
    // printPattern4(input_size);
    // printPattern5(input_size);
    // printPattern6(input_size);
    // printPattern7(input_size);
    printPattern8(input_size);
    // printPattern21(input_size);

    return 0;
}