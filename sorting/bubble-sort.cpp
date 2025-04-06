#include <bits/stdc++.h>
using namespace std;

// It pushes highest element to the right of the array,after every iteration of the outer loop;
void bubble_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int did_swap = 0;
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                did_swap = 1;
            }
        }

        if (did_swap == 0)
            break; // if array is already in ascending order, which will improve its time complexity to omega(n) from O(n^2);
    }
}

int main()
{
    vector<int> vc = {13, 46, 24, 52, 20, 9};
    bubble_sort(vc);

    for (auto elem : vc)
    {
        cout << elem << endl;
    }

    return 0;
}