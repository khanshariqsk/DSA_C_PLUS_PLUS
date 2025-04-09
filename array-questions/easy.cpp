#include <bits/stdc++.h>
using namespace std;

// Question 1 ==> Find the Largest element in an array
int largest_element(int arr[], int size)
{
    /**
     * Finds the largest element in an array.
     *
     * @param arr   Input array
     * @param size  Size of the array
     *
     * * Time Complexity:  O(n)  (Single pass through array)
     * * Space Complexity: O(1)  (Uses constant extra space)
     *
     * * How it works:
     *   1. Initializes with first element
     *   2. Compares each subsequent element
     *   3. Updates largest found value
     *
     * * Edge cases handled:
     *   - Empty array (size=0) would need separate handling
     *   - All equal elements
     */

    int largest_elem = arr[0]; // Initialize with first element

    for (int i = 1; i < size; i++) // Traverse from second element
    {
        if (arr[i] > largest_elem) // Compare current element
        {
            largest_elem = arr[i]; // Update largest if current is larger
        }
    }

    return largest_elem;
}

// Question 2 ==> Find the second largest and second smallest element from the array.
vector<int> second_largest_and_smallest_element(int a[], int n)
{
    /**
     * Finds second largest and second smallest elements in an array.
     *
     * @param a  Input array
     * @param n  Size of the array
     *
     * * Time Complexity:  O(n)  (Single pass through array)
     * * Space Complexity: O(1)  (Uses constant extra space)
     *
     * * How it works:
     *   1. Tracks largest/second_largest
     *   2. Tracks smallest/second_smallest
     *   3. Updates during traversal
     *
     * * Edge cases handled:
     *   - All equal elements (returns INT_MIN/INT_MAX)
     *   - Arrays with <2 unique elements
     */

    // Initialize with extreme values
    int largest = numeric_limits<int>::min();
    int second_largest = numeric_limits<int>::min();
    int lowest = numeric_limits<int>::max();
    int second_lowest = numeric_limits<int>::max();

    for (int i = 0; i < n; i++) // Traverse entire array
    {
        // Handle largest elements
        if (a[i] > largest) // New largest found
        {
            second_largest = largest; // Demote current largest
            largest = a[i];           // Update largest
        }
        else if (a[i] < largest && a[i] > second_largest) // New second largest
        {
            second_largest = a[i];
        }

        // Handle smallest elements
        if (a[i] < lowest) // New smallest found
        {
            second_lowest = lowest; // Demote current smallest
            lowest = a[i];          // Update smallest
        }
        else if (a[i] > lowest && a[i] < second_lowest) // New second smallest
        {
            second_lowest = a[i];
        }
    }

    vector<int> res = {second_largest, second_lowest};
    return res;
}

// Question 3 ==> Check if an Array is Sorted
bool check_if_array_is_sorted(int arr[], int n)
{
    /**
     * Checks if array is sorted in non-decreasing order.
     *
     * @param arr  Input array
     * @param n    Size of the array
     *
     * * Time Complexity:  O(n)  (Single pass through array)
     * * Space Complexity: O(1)  (No extra space used)
     *
     * * How it works:
     *   1. Compares each element with next
     *   2. Returns false if any element > next
     *   3. Returns true if all elements <= next
     *
     * * Edge cases handled:
     *   - Empty array (returns true)
     *   - Single element array (returns true)
     */

    for (int i = 0; i < n - 1; i++) // Compare adjacent pairs
    {
        if (arr[i] > arr[i + 1]) // Found unsorted pair
            return false;
    }
    return true; // All elements in order
}

// Question 4 ==> Remove Duplicates from Sorted Array and return unique elements count
int remove_duplicates_get_unique_count(int arr[], int n)
{
    /**
     * Removes duplicates from sorted array in-place and returns count of unique elements.
     *
     * @param arr  Input array (must be sorted)
     * @param n    Size of the array
     *
     * * Time Complexity:  O(n)  (Single pass through array)
     * * Space Complexity: O(1)  (In-place modification)
     *
     * * How it works:
     *   1. Uses two-pointer technique
     *   2. j tracks position for next unique element
     *   3. i scans through array
     *
     * * Edge cases handled:
     *   - Empty array (returns 0)
     *   - All elements same (returns 1)
     */

    if (n == 0)
        return 0; // Handle empty array

    int j = 0; // Pointer for unique elements

    for (int i = 1; i < n; i++) // Start from second element
    {
        if (arr[i - 1] != arr[i]) // Found new unique element
        {
            arr[j] = arr[i - 1]; // Store previous unique
            j++;
        }
    }

    arr[j] = arr[n - 1]; // Store last element
    j++;

    return j; // Return count of unique elements
}

/**
 * Reverses a subarray from index `start` to `end`.
 *
 * @param arr    Input array
 * @param start  Start index
 * @param end    End index
 *
 * * Time Complexity:  O((end - start)/2)  (Half the subarray length)
 * * Space Complexity: O(1)  (Uses only a single `temp` variable)
 */
void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start]; // Single temp variable (O(1) space)
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Question 5(a) ==> Rotate array left by K elements
void rotate_array_left_by_kth_place(int arr[], int n, int k)
{

    /**
     * Rotates an array left by `k` positions using a temporary array.
     *
     * @param arr  Input array
     * @param n    Size of the array
     * @param k    Number of positions to rotate left
     *
     * * Time Complexity:  O(n)  (Each element is moved exactly once)
     * * Space Complexity: O(k)  (Uses a temporary array of size `k`)
     *
     * * Advantages:
     *   - Simple and easy to understand.
     *   - Optimal time complexity (O(n)).
     *
     * * Trade-offs:
     *   - Allocates extra memory (O(k)), which can be inefficient for large `k`.
     *   - Not in-place (requires additional space).
     */
    // k = k % n;

    // int temp_array[k];
    // for (int i = 0; i < k; i++)
    // {
    //     temp_array[i] = arr[i];
    // }

    // for (int i = k; i < n; i++)
    // {
    //     arr[i - k] = arr[i];
    // }

    // for (int i = 0; i < k; i++)
    // {
    //     arr[n - k + i] = temp_array[i];
    // }

    // OR =====================================>

    /**
     * Rotates an array left by `k` positions using reversal method.
     *
     * @param arr  Input array
     * @param n    Size of the array
     * @param k    Number of positions to rotate left
     *
     * * Time Complexity:  O(2n) ≈ O(n)  (Each element is moved twice)
     * * Space Complexity: O(1)  (In-place, no extra memory)
     *
     * * Advantages:
     *   - No extra memory required (in-place rotation).
     *   - Works well for large `k` (no memory overhead).
     *
     * * Trade-offs:
     *   - Slightly slower than the original method (but still O(n)).
     *   - Requires understanding of the reversal trick.
     */

    k = k % n;              // Handle cases where k > n
    reverse(arr, 0, k - 1); // Reverse first `k` elements
    reverse(arr, k, n - 1); // Reverse remaining `n - k` elements
    reverse(arr, 0, n - 1); // Reverse entire array
}

// Question 5(b) ==> Rotate array right by K elements
void rotate_array_right_by_kth_place(int arr[], int n, int k)
{

    /**
     * Rotates an array right by `k` positions using a temporary array.
     *
     * @param arr  Input array
     * @param n    Size of the array
     * @param k    Number of positions to rotate right
     *
     * * Time Complexity:  O(n)  (Each element is moved exactly once)
     * * Space Complexity: O(k)  (Uses a temporary array of size `k`)
     *
     * * How it works:
     *   1. Stores last `k` elements in temp array
     *   2. Shifts remaining elements right by `k` positions
     *   3. Places temp elements at beginning
     *
     * * Best when:
     *   - `k` is small (memory efficient)
     *   - Simple implementation preferred
     */

    // k = k % n; // Handle k > n cases
    // int temp[k];

    // // Store last k elements
    // for (int i = 0; i < k; i++)
    // {
    //     temp[i] = arr[n - k + i];
    // }

    // // Shift elements right
    // for (int i = n - 1; i >= k; i--)
    // {
    //     arr[i] = arr[i - k];
    // }

    // // Place temp elements at start
    // for (int i = 0; i < k; i++)
    // {
    //     arr[i] = temp[i];
    // }

    // OR =====================================>

    /**
     * Rotates an array right by `k` positions using triple reversal method.
     *
     * @param arr  Input array
     * @param n    Size of the array
     * @param k    Number of positions to rotate right
     *
     * * Time Complexity:  O(2n) ≈ O(n) (Each element moved twice)
     * * Space Complexity: O(1) (In-place rotation)
     *
     * * Algorithm:
     *   1. Reverse just the last `k` elements
     *   2. Reverse the remaining first `n-k` elements
     *   3. Reverse the entire array
     *
     * * Advantages over standard reversal method:
     *   - More intuitive partition of array sections
     *   - Same O(1) space benefit
     *   - More cache-friendly memory access pattern
     *
     * * Example:
     *   arr = [1,2,3,4,5], k=2
     *   1. Reverse last 2: [1,2,3,5,4]
     *   2. Reverse first 3: [3,2,1,5,4]
     *   3. Reverse all: [4,5,1,2,3] (correct result)
     */

    k = k % n;                  // Handle cases where k > n
    reverse(arr, n - k, n - 1); // Reverse last `n - k to n - 1` elements
    reverse(arr, 0, n - k - 1); // Reverse remaining `0 to n - k` elements
    reverse(arr, 0, n - 1);     // Reverse entire array
}

// Question 6 ==> Rotate array right by K elements
void move_zeroes_to_last(int arr[], int n)
{
    /**
     * Moves all zeroes to the end of the array (brute force approach).
     *
     * @param arr  Input array
     * @param n    Size of the array
     *
     * * Time Complexity:  O(n²)  (Nested loops in worst case)
     * * Space Complexity: O(1)   (In-place modification)
     *
     * * How it works:
     *   1. For each zero found, searches ahead for non-zero
     *   2. Swaps zero with first found non-zero
     *   3. Stops when no more non-zero elements ahead
     *
     * * Disadvantages:
     *   - Inefficient for arrays with many zeroes
     *   - Worst case scenario (all zeroes) performs n² operations
     */

    // for (int i = 0; i < n; i++)
    // {

    //     if (arr[i] == 0)
    //     {

    //         int j = i;
    //         while (j < n)
    //         {
    //             if (arr[j] != 0)
    //             {
    //                 int temp = arr[i];
    //                 arr[i] = arr[j];
    //                 arr[j] = temp;
    //                 break;
    //             }

    //             j++;
    //         }

    //         if (j >= n)
    //             break;
    //     }
    // }

    // OR =====================================>

    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     * Method:
     * 1. Store non-zeroes in temp array
     * 2. Write them back to original array
     * 3. Fill remaining positions with zeroes
     *
     * Advantages:
     * - Simple and easy to understand
     * - Preserves relative order of non-zero elements
     *
     * Disadvantages:
     * - Uses extra O(n) space
     * - Two passes through array
     */

    // vector<int> temp;

    // // First pass: collect all non-zero elements
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] != 0)
    //     {
    //         temp.push_back(arr[i]);
    //     }
    // }

    // // Second pass: reconstruct array
    // for (int i = 0; i < n; i++)
    // {
    //     if (i < temp.size())
    //     {
    //         arr[i] = temp[i]; // Write non-zero elements
    //     }
    //     else
    //     {
    //         arr[i] = 0; // Fill remaining with zeroes
    //     }
    // }

    // OR =====================================>

    /**
     * Moves all zeroes to the end of the array (optimal approach).
     *
     * @param arr  Input array
     * @param n    Size of the array
     *
     * * Time Complexity:  O(n)  (Single pass through array)
     * * Space Complexity: O(1)  (In-place modification)
     *
     * * How it works:
     *   1. Finds first zero (j)
     *   2. For each subsequent non-zero, swaps with j
     *   3. Increments j after each swap
     *
     * * Advantages:
     *   - Single pass through array
     *   - Handles all cases efficiently
     *   - Optimal for arrays with many zeroes
     */

    int j = -1;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return;

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;

            j++;
        }
    }
}

// Question 7 ==> Linear Search
int linears_search(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

// Question 8(a) ==> Union of Two Sorted Arrays
vector<int> union_two_sorted_arrays(int arr1[], int n1, int arr2[], int n2)
{
    /**
     * Computes the union of two sorted arrays with unique elements.
     *
     * @param arr1  First sorted array
     * @param n1    Size of first array
     * @param arr2  Second sorted array
     * @param n2    Size of second array
     * @return      Vector containing union of both arrays (sorted and unique)
     *
     * * Time Complexity: O(n1 + n2) - Single pass through both arrays
     * * Space Complexity: O(1) auxiliary space (O(n1 + n2) for result)
     *
     * * Algorithm:
     *   1. Uses two-pointer technique to merge arrays
     *   2. Checks for duplicates by comparing with last added element
     *   3. Handles remaining elements after one array is exhausted
     *
     * * Edge Cases Handled:
     *   - Empty input arrays
     *   - All elements same in both arrays
     *   - One array completely contained in another
     */

    vector<int> union_array; // Result container

    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2

    // Merge process while both arrays have elements
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            // Add from arr1 if not duplicate
            if (union_array.empty() || union_array.back() != arr1[i])
            {
                union_array.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            // Add from arr2 if not duplicate
            if (union_array.empty() || union_array.back() != arr2[j])
            {
                union_array.push_back(arr2[j]);
            }
            j++;
        }
    }

    // Add remaining elements from arr1
    while (i < n1)
    {
        if (union_array.empty() || union_array.back() != arr1[i])
        {
            union_array.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements from arr2
    while (j < n2)
    {
        if (union_array.empty() || union_array.back() != arr2[j])
        {
            union_array.push_back(arr2[j]);
        }
        j++;
    }

    return union_array;
}

// Question 8(b) ==> Intersection of Two Sorted Arrays
vector<int> intersection_two_sorted_arrays(int arr1[], int n1, int arr2[], int n2)
{
    /**
     * Computes intersection using visited marker approach.
     *
     * @note This version is less efficient than two-pointer method
     *       but shown for educational purposes.
     *
     * * Time Complexity: O(n1 * n2) - Nested loops
     * * Space Complexity: O(n2) - For visited array
     *
     * * How it works:
     *   1. Marks elements in arr2 as visited when matched
     *   2. Avoids duplicate matches
     *   3. Early termination when arr2 elements become larger
     */

    // vector<int> ans;
    // int vis[n2] = {0}; // Visited marker array

    // for (int i = 0; i < n1; i++)
    // {
    //     for (int j = 0; j < n2; j++)
    //     {
    //         if (arr1[i] == arr2[j] && vis[j] == 0)
    //         {
    //             ans.push_back(arr1[i]);
    //             vis[j] = 1; // Mark as visited
    //             break;
    //         }
    //         if (arr2[j] > arr1[i])
    //             break; // Early termination
    //     }
    // }

    // return ans;

    // OR =====================================>

    /**
     * Computes the intersection of two sorted arrays.
     *
     * @param arr1  First sorted array (non-decreasing order)
     * @param n1    Size of first array
     * @param arr2  Second sorted array (non-decreasing order)
     * @param n2    Size of second array
     * @return      Vector containing intersection of both arrays (sorted)
     *
     * * Time Complexity: O(n1 + n2) - Efficient two-pointer approach
     * * Space Complexity: O(1) auxiliary space (O(min(n1,n2)) for result)
     *
     * * Algorithm:
     *   1. Uses two-pointer technique to find common elements
     *   2. Skips duplicates by checking against last added element
     *   3. Handles remaining elements after one array is exhausted
     *
     * * Edge Cases Handled:
     *   - Empty input arrays
     *   - No intersection elements
     *   - Duplicate elements within single array
     *   - One array completely contained in another
     */

    vector<int> intersection_array; // Result container

    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            i++; // Move smaller element's pointer
        }
        else if (arr2[j] < arr1[i])
        {
            j++; // Move smaller element's pointer
        }
        else
        {
            // For duplicate check but in this intersection duplicate is allowed that is why this code is commented out
            // if (intersection_array.empty() || intersection_array.back() != arr1[i])
            // {
            // }

            intersection_array.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return intersection_array;
}

int main()
{
    int array_size_1 = 6;
    int arr1[array_size_1] = {3, 4, 6, 7, 9, 9};

    int array_size_2 = 6;
    int arr2[array_size_2] = {1, 5, 7, 8, 8, 10};

    vector<int> intersection_array = intersection_two_sorted_arrays(arr1, array_size_1, arr2, array_size_2);

    for (int it : intersection_array)
    {
        cout << it << endl;
    }
    return 0;

    return 0;
}