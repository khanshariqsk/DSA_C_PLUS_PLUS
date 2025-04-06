#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int swap_index = start;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] < arr[start])
        {
            swap_index++;

            int temp = arr[i];
            arr[i] = arr[swap_index];
            arr[swap_index] = temp;
        }
    }

    int temp = arr[start];
    arr[start] = arr[swap_index];
    arr[swap_index] = temp;

    return swap_index;
}

void quick_sort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int partition_index = partition(arr, start, end);
    quick_sort(arr, start, partition_index - 1);
    quick_sort(arr, partition_index + 1, end);
}

int main()
{
    vector<int> vc = {13, 46, 24, 52, 20, 9, 7};
    quick_sort(vc, 0, vc.size() - 1);

    for (int num : vc)
        cout << num << " ";
    return 0;
}