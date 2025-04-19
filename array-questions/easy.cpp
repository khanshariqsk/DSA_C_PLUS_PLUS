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

int find_missing_number_in_array(int arr[], int n)
{

    /**
     * Finds the missing number in a sequence by checking adjacent differences.
     *
     * @param arr  Input array (expected to contain numbers from 1 to n with one missing)
     * @param n    Size of the array (n-1 elements, since one is missing)
     *
     * * Time Complexity: O(n)  (Single pass through array)
     * * Space Complexity: O(1) (No extra space used)
     *
     * * How it works:
     *   1. Checks if the difference between consecutive elements > 1.
     *   2. If found, returns the missing number (current element + 1).
     *   3. Handles edge cases where the missing number is at the start or end.
     *
     * * Edge Cases Handled:
     *   - Missing number at the beginning (e.g., [2, 3, 4] → returns 1)
     *   - Missing number at the end (e.g., [1, 2, 3] → returns 4)
     *   - Missing number in the middle (e.g., [1, 3, 4] → returns 2)
     */
    // for (int i = 0; i < n - 2; i++)
    // {
    //     if (arr[i + 1] - arr[i] > 1)
    //     {
    //         return arr[i] + 1;
    //     }
    // }

    // if (arr[n - 2] == n)
    // { // Last element is n → missing is at start
    //     return arr[0] - 1;
    // }

    // return arr[n - 2] + 1; // Default: missing is at end

    // OR =====================================>
    /**
     * Finds the missing number using the sum of natural numbers formula.
     *
     * @param arr  Input array (expected to contain numbers from 1 to n with one missing)
     * @param n    Size of the array (n-1 elements, since one is missing)
     *
     * * Time Complexity: O(n)  (Single pass to compute sum)
     * * Space Complexity: O(1) (Constant extra space)
     *
     * * How it works:
     *   1. Computes the expected sum of first n natural numbers: (n*(n+1))/2.
     *   2. Computes the actual sum of array elements.
     *   3. Returns the difference (expected - actual).
     *
     * * Edge Cases Handled:
     *   - Works for any missing number in the range [1, n].
     *
     * * Limitations:
     *   - Risk of integer overflow for large n (e.g., n > 10^5).
     */

    // int sum = (n * (n + 1)) / 2; // Expected sum of 1 to n
    // int s2 = 0;
    // for (int i = 0; i < n - 1; i++)
    // { // Actual sum of array
    //     s2 += arr[i];
    // }
    // int missingNum = sum - s2; // Missing number
    // return missingNum;

    // OR =====================================>
    /**
     * Finds the missing number using XOR properties.
     *
     * @param arr  Input array (expected to contain numbers from 1 to n with one missing)
     * @param n    Size of the array (n-1 elements, since one is missing)
     *
     * * Time Complexity: O(n)  (Single pass through array)
     * * Space Complexity: O(1) (Constant extra space)
     *
     * * How it works:
     *   1. XOR all array elements (xor1).
     *   2. XOR all numbers from 1 to n (xor2).
     *   3. The missing number is xor1 ^ xor2 (XOR cancels out duplicates).
     *
     * * Advantages:
     *   - No risk of integer overflow (unlike sum approach).
     *   - Works for any unsorted sequence.
     *
     * * Edge Cases Handled:
     *   - Works for any missing number in the range [1, n].
     */

    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor1 ^= arr[i];  // XOR of array elements
        xor2 ^= (i + 1); // XOR of 1 to n-1
    }
    xor2 ^= n;          // Include n in XOR
    return xor1 ^ xor2; // Missing number
}

int maximum_consecutive_ones(int arr[], int n)
{
    /**
     * Finds the maximum consecutive 1's by tracking positions of 0's.
     *
     * @param arr  Binary array (0's and 1's)
     * @param n    Size of the array
     *
     * * Time Complexity: O(n)  (Two passes: one to find first 0, one to scan rest)
     * * Space Complexity: O(1) (Uses only a few variables)
     *
     * * How it works:
     *   1. Finds the first occurrence of 0 (j).
     *   2. Tracks the distance between consecutive 0's to compute 1's sequences.
     *   3. Updates max_count whenever a longer sequence is found.
     *
     * * Edge Cases Handled:
     *   - All 1's: Returns n
     *   - All 0's: Returns 0
     *   - Single 0 in 1's: Returns max(left or right segment)
     */

    // int j = 0;
    // // Find first 0 (if any)
    // while (j < n)
    // {
    //     if (arr[j] == 0)
    //         break;
    //     j++;
    // }
    // int max_count = j; // Initialize with count of leading 1's

    // // Scan remaining array
    // for (int i = j; i < n; i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         // Update max_count with the length of 1's between j and i
    //         max_count = max(max_count, i - j - 1);
    //         j = i; // Move j to current 0
    //     }
    // }
    // // Check trailing 1's after last 0
    // max_count = max(max_count, n - j - 1);
    // return max_count;

    // OR

    /**
     * Finds the maximum consecutive 1's using a running counter.
     *
     * @param arr  Binary array (0's and 1's)
     * @param n    Size of the array
     *
     * * Time Complexity: O(n)  (Single pass)
     * * Space Complexity: O(1) (Uses only two variables)
     *
     * * How it works:
     *   1. Increments `current` for every consecutive 1.
     *   2. Resets `current` to 0 when a 0 is encountered.
     *   3. Updates `max_count` whenever `current` exceeds it.
     *
     * * Advantages:
     *   - Simpler and more intuitive.
     *   - Single pass (more efficient in practice).
     *
     * * Edge Cases Handled:
     *   - All 1's: Returns n
     *   - All 0's: Returns 0
     */

    int max_count = 0, current = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            current++;
            max_count = max(max_count, current);
        }
        else
        {
            current = 0; // Reset on 0
        }
    }
    return max_count;
}

int number_appears_once(int arr[], int n)
{
    int num = 0;

    for (int i = 0; i < n; i++)
    {
        num = num ^ arr[i];
    }

    return num;
}

int longest_subarray_with_sum_k(int arr[], int n, int k)
{
    // Brute force approach
    // int longest = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];

    //         if (sum == k && j - i + 1 > longest)
    //         {
    //             longest = j - i + 1;
    //         }
    //     }
    // }

    // return longest;

    // Better Approach (this solution is the optimal solution if the array contains negative numbers)
    // unordered_map<long long, int> prefix_map;
    // long long sum = 0;
    // int max_len = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     sum += arr[i];

    //     if (sum == k)
    //     {
    //         max_len = max(max_len, i + 1);
    //     }

    //     if (prefix_map.count(sum - k))
    //     {
    //         max_len = max(max_len, i - prefix_map[sum - k]);
    //     }

    //     // The below if condition is used to find the largest subarray because if we encounter zero at any later index, the subsequent sum will remain the same, which will eventually replace the previous index value with the latest one, thereby shrinking the max_len.for finding shortest subarray we dont need to add this condition eg for reference [2,0,0,3] k=3

    //     if (!prefix_map.count(sum))
    //     {
    //         prefix_map[sum] = i;
    //     }
    // }

    // return max_len;

    // Optimal Approach (only works for positive and zero numbers)
    int left = 0, right = 0;
    long long sum = arr[0];
    int maxLen = 0;

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
            sum += arr[right];
    }

    return maxLen;
}

int main()
{
    int array_size = 10;
    int arr[array_size] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    // int array_size = 5;
    // int arr[array_size] = {1, 2, 1, 2, 1};

    int res = longest_subarray_with_sum_k(arr, array_size, 3);

    cout << res << endl;

    // for (int it : intersection_array)
    // {
    //     cout << it << endl;
    // }
    return 0; 
}