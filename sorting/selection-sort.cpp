#include <bits/stdc++.h>
using namespace std;

// It pushes lowest element to the left of the array,after every iteration of the outer loop;
void selection_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (i != min_index)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main()
{
    vector<int> vc = {13, 46, 24, 52, 20, 9};
    selection_sort(vc);

    for (auto elem : vc)
    {
        cout << elem << endl;
    }

    return 0;
}