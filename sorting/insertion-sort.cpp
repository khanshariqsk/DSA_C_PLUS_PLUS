#include <bits/stdc++.h>
using namespace std;

// if array is already in ascending order, which will improve its time complexity to omega(n) from O(n^2) because the while loop condition will never get triggered;
void insertion_sort(vector<int> &arr)
{
    for (int i = 0; i <= arr.size() - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }
}

int main()
{
    vector<int> vc = {13, 46, 24, 52, 20, 9};
    insertion_sort(vc);

    for (auto elem : vc)
    {
        cout << elem << endl;
    }

    return 0;
}