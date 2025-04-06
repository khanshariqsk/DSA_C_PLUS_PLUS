#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp(end - start + 1);

    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];

    for (int p = 0; p < k; p++)
        arr[start + p] = temp[p];
}

void merge_sort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    vector<int> vc = {13, 46, 24, 52, 20, 9, 7};
    merge_sort(vc, 0, vc.size() - 1);

    for (int num : vc)
        cout << num << " ";
    return 0;
}