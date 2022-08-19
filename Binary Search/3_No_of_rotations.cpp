#include <iostream>
#define rep(i, size) for (int i = 0; i < size; i++)
using namespace std;

// how many times is a sorted array rotated
int no_of_rotations(int arr[], int n)
{
    int mid;
    int l = 0, h = n - 1;
    if (arr[0] < arr[n - 1])
        return arr[0];
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
        {
            return arr[mid];
        }

        if (arr[l] < arr[mid])
            l = mid + 1;
        else if (arr[h] >= arr[mid])
            h = mid - 1;
    }
}
void NoOfRotationsWithDuplicates(int arr[], int size, int low, int high, int &min_index)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        int prev = (mid - 1) % size;
        int next = (mid + size - 1) % size;

        // Remeber the order of the if else ladder
        // This is the only order that will work
        // for right rotated array, <= sign will occur in the 1st condition but not in the 2nd condition
        // This is done to operate over duplicate arrays
        // If there were no duplicates, we could have jus written < sign in both conditions(TRY IT YOURSELF)
        if (arr[mid] < arr[prev] && arr[mid] <= arr[next])
            min_index = mid;

        // if the left part is sorted, recur for the right one
        // Also see that WE ARE NOT USING mid + 1 because we need to consider that position too
        else if (arr[low] < arr[mid])
            NoOfRotationsWithDuplicates(arr, size, mid, high, min_index);

        // if the right part is sorted, recur for the left part
        // Also see that WE ARE NOT USING mid - 1 because we need to consider that position too
        else if (arr[mid] < arr[high])
            NoOfRotationsWithDuplicates(arr, size, low, mid, min_index);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    rep(i, n) cin >> arr[i];

    int low = 0;
    int high = n- 1;
    int min_index = 0;

    NoOfRotationsWithDuplicates(arr, n, low, high, min_index);
    cout << "No of rotations :- " << (n- min_index) % n;
    return 0;
}