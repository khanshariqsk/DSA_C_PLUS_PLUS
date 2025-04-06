#include <bits/stdc++.h>
using namespace std;

void print_name_n_times(int n, int count = 1)
{
    if (count > n)
        return;
    cout << "Shariq" << endl;
    print_name_n_times(n, count + 1);
}

void print_linearly_to_n(int n, int count = 1)
{
    if (count > n)
        return;
    cout << count << endl;
    print_linearly_to_n(n, count + 1);
}

void print_reverse_from_n(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    print_reverse_from_n(n - 1);
}

int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

// For array reverse using two pointer:
void reverse_array(int arr[], int ind1, int ind2)
{
    if (ind1 >= ind2)
        return;
    swap(arr[ind1], arr[ind2]);
    reverse_array(arr, ind1 + 1, ind2 - 1);
}
// For array reverse using one pointer:
void reverse_array_single_pointer(int arr[], int size, int index)
{
    if (index >= size / 2)
        return;

    swap(arr[index], arr[size - index - 1]);
    reverse_array_single_pointer(arr, size, index + 1);
}

void reverse_string(string &str, int size, int index)
{
    if (index >= size / 2)
        return;
    swap(str[index], str[size - index - 1]);
    reverse_string(str, size, index + 1);
}

string check_parindrome(string str)
{
    string copy_str = str;
    reverse_string(str, str.size(), 0);
    return copy_str == str ? "true" : "false";
}

void fibonacci(int n)
{
    if (n < 1)
        return;

    int a = 0;
    int b = 1;

    cout << a << endl;
    n > 1 && cout << b << endl;

    for (int i = 3; i <= n; i++)
    {
        cout << a + b << endl;

        int temp = a + b;
        a = b;
        b = temp;
    }
}

int fibonacci_recursion(int num)
{
    if (num <= 1)
        return num;

    return fibonacci_recursion(num - 1) + fibonacci_recursion(num - 2);
}

int main()
{
    // print_name_n_times(5);
    // print_linearly_to_n(5);
    // print_reverse_from_n(5);
    // cout << sum(5);
    // cout << factorial(5);

    // For array reverse using two pointer:
    //  int size_array = 5;
    //  int arr[size_array] = {3,4,6,9,1};
    //  reverse_array(arr,0,size_array -1);
    //  for(auto v:arr){
    //      cout << v << endl;
    //  }

    // For array reverse using one pointer:
    // int size_array = 5;
    // int arr[size_array] = {3, 4, 6, 9, 1};
    // reverse_array(arr, size_array, 0);
    // for (auto v : arr)
    // {
    //     cout << v << endl;
    // }
    // return 0;

    // cout << check_parindrome("nayan");

    // fibonacci(10);

    cout << fibonacci_recursion(4);

    return 0;
}