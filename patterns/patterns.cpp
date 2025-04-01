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

//      *
//     ***
//    *****
//   *******
//  *********
// ***********
// ***********
//  *********
//   *******
//    *****
//     ***
//      *
void printPattern9(int n)
{

    for (int i = 1; i <= n; i++)
    {
        int upper_spaces = n - i;
        int upper_stars = 2 * i - 1;
        for (int j = 1; j <= upper_spaces; j++)
            cout << "  ";
        for (int j = 1; j <= upper_stars; j++)
            cout << "* ";
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        int lower_spaces = i - 1;
        int lower_stars = 2 * (n - i) + 1;
        for (int j = 1; j <= lower_spaces; j++)
            cout << "  ";

        for (int j = 1; j <= lower_stars; j++)
            cout << "* ";

        cout << endl;
    }
}

// *
// **
// ***
// ****
// *****
// ******
// *****
// ****
// ***
// **
// *
void printPattern10(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // OR

    // for (int i = 1; i <= 2 * n - 1; i++)
    // {
    //     if (i <= n)
    //     {
    //         for (int j = 1; j <= i; j++)
    //         {
    //             cout << "* ";
    //         }
    //         cout << endl;
    //     }
    //     else
    //     {
    //         for (int j = 1; j <= 2 * n - i; j++)
    //         {
    //             cout << "* ";
    //         }
    //         cout << endl;
    //     }
    // }
}

// 1
// 01
// 101
// 0101
// 10101
// 010101
void printPattern11(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (((i + j) % 2 == 0))
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }

        cout << endl;
    }
}

// 1          1
// 12        21
// 123      321
// 1234    4321
// 12345  54321
// 123456654321
void printPattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << "  ";
        }

        for (int j = i; j > 0; j--)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}

// 1
// 2  3
// 4  5  6
// 7  8  9  10
// 11  12  13  14  15
// 16  17  18  19  20  21
void printPattern13(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << count << " ";
            count++;
        }

        cout << endl;
    }
}

// A
// A B
// A B C
// A B C D
// A B C D E
// A B C D E F
void printPattern14(int n)
{

    // for (int i = 1; i <= n; i++)
    // {
    //     int initial_ascii_value = (int)'A';
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << (char)initial_ascii_value << " ";
    //         initial_ascii_value++;
    //     }

    //     cout << endl;
    // }

    // OR

    for (int i = 1; i <= n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i - 1; ch++)
        {
            cout << ch << " ";
        }

        cout << endl;
    }
}

// A B C D E F
// A B C D E
// A B C D
// A B C
// A B
// A
void printPattern15(int n)
{

    // for (int i = 1; i <= n; i++)
    // {
    //     int initial_ascii_value = (int)'A';
    //     for (int j = 1; j <= n - i + 1; j++)
    //     {
    //         cout << (char)initial_ascii_value << " ";
    //         initial_ascii_value++;
    //     }

    //     cout << endl;
    // }

    // OR

    for (int i = 1; i <= n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + n - i; ch++)
        {
            cout << ch << " ";
        }

        cout << endl;
    }
}

// A
// B B
// C C C
// D D D D
// E E E E E
// F F F F F F
void printPattern16(int n)
{

    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + i - 1;

        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
        }

        cout << endl;
    }
}

//      A
//     ABA
//    ABCBA
//   ABCDCBA
//  ABCDEDCBA
// ABCDEFEDCBA
void printPattern17(int n)
{

    for (int i = 1; i <= n; i++)
    {
        int spaces = n - i;
        int characs = 2 * i - 1;

        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        char ch = 'A';
        for (int j = 1; j <= characs; j++)
        {
            if (j <= i)
            {
                cout << ch;
                if (j != i)
                    ch++;
            }
            else
            {
                ch--;
                cout << ch;
            }
        }

        cout << endl;
    }
}

// F
// E F
// D E F
// C D E F
// B C D E F
// A B C D E F
void printPattern18(int n)
{

    for (int i = 1; i <= n; i++)
    {
        char end_char = 'A' + n - 1;
        char start_char = end_char - i + 1;

        for (start_char; start_char <= end_char; start_char++)
        {
            cout << start_char << " ";
        }

        cout << endl;
    }
}

// ************
// *****  *****
// ****    ****
// ***      ***
// **        **
// *          *
// *          *
// **        **
// ***      ***
// ****    ****
// *****  *****
// ************
void printPattern19(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }

        for (int j = 1; j <= (i + i - 2); j++)
        {
            cout << "  ";
        }

        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << "  ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

// *          *
// **        **
// ***      ***
// ****    ****
// *****  *****
// ************
// *****  *****
// ****    ****
// ***      ***
// **        **
// *          *
void printPattern20(int n)
{

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << "  ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }

        for (int j = 1; j <= (i + i - 2); j++)
        {
            cout << "  ";
        }

        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }

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

// 6 6 6 6 6 6 6 6 6 6 6
// 6 5 5 5 5 5 5 5 5 5 6
// 6 5 4 4 4 4 4 4 4 5 6
// 6 5 4 3 3 3 3 3 4 5 6
// 6 5 4 3 2 2 2 3 4 5 6
// 6 5 4 3 2 1 2 3 4 5 6
// 6 5 4 3 2 2 2 3 4 5 6
// 6 5 4 3 3 3 3 3 4 5 6
// 6 5 4 4 4 4 4 4 4 5 6
// 6 5 5 5 5 5 5 5 5 5 6
// 6 6 6 6 6 6 6 6 6 6 6
void printPattern22(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int size_copy = n;
        for (int j = i - 1; j > 0; j--)
        {
            cout << size_copy << " ";
            if (j != i)
                size_copy--;
        }

        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << n - i + 1 << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << size_copy << " ";
            size_copy++;
        }

        cout << endl;
    }

    for (int i = 2; i <= n; i++)
    {
        int size_copy = n;
        for (int j = n - i; j > 0; j--)
        {
            cout << size_copy << " ";
            size_copy--;
        }

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << i << " ";
        }

        for (int j = 1; j <= n - i; j++)
        {
            size_copy++;
            cout << size_copy << " ";
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
    // printPattern8(input_size);
    // printPattern9(input_size);
    // printPattern10(input_size);
    // printPattern11(input_size);
    // printPattern12(input_size);
    // printPattern13(input_size);
    // printPattern14(input_size);
    // printPattern15(input_size);
    // printPattern16(input_size);
    // printPattern17(input_size);
    // printPattern18(input_size);
    // printPattern19(input_size);
    // printPattern20(input_size);
    // printPattern21(input_size);
    printPattern22(input_size);

    return 0;
}