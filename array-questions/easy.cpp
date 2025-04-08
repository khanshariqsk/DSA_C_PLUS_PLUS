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

// Question 4(a) ==> Rotate array left by K elements
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

// Question 4(b) ==> Rotate array right by K elements
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

    if (j < 0)
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

int main()
{
    int array_size = 9;
    int arr[array_size] = {1, 6, 0, 0, 2, 3, 0, 4, 0, 1};
    move_zeroes_to_last(arr, array_size);
    for (int it : arr)
    {
        cout << it << endl;
    }
    return 0;

    return 0;
}