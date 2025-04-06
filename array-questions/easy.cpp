#include <bits/stdc++.h>
using namespace std;

// Question 1 ==> Find the Largest element in an array
int largest_element(int arr[], int size)
{
    int largest_elem = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest_elem)
        {
            largest_elem = arr[i];
        }
    }

    return largest_elem;
}

// Question 2 ==> Find the second largest and second smallest element from the array.
vector<int> second_largest_smallest_element(int a[], int n)
{
    int largest = numeric_limits<int>::min(), second_largest = numeric_limits<int>::min();
    int lowest = numeric_limits<int>::max(), second_lowest = numeric_limits<int>::max();

    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            second_largest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > second_largest)
        {
            second_largest = a[i];
        }

        if (a[i] < lowest)
        {
            second_lowest = lowest;
            lowest = a[i];
        }
        else if (a[i] > lowest && a[i] < second_lowest)
        {
            second_lowest = a[i];
        }
    }

    vector<int> res = {second_largest, second_lowest};

    return res;
}

int main()
{
    int array_size = 7;
    int arr[array_size] = {13, 44, 24, 52, 49, 9, 12};
    auto result = second_largest_smallest_element(arr, array_size);
    for (auto v : result)
    {
        cout << v << endl;
    }
    return 0;
}