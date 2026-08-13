#include <iostream>
using namespace std;

// Iterative Binary Search
int iterativeBinarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

// Recursive Binary Search
int recursiveBinarySearch(int arr[], int low, int high, int target)
{
    if(low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if(arr[mid] == target)
    {
        return mid;
    }

    if(arr[mid] < target)
    {
        return recursiveBinarySearch(arr, mid + 1, high, target);
    }

    return recursiveBinarySearch(arr, low, mid - 1, target);
}

int main()
{
    int n;

    cout << "Enter number of book codes: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted book codes:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;

    cout << "Enter target code: ";
    cin >> target;

    int ans1 = iterativeBinarySearch(arr, n, target);

    if(ans1 == -1)
        cout << "Iterative Binary Search: Not Found\n";
    else
        cout << "Iterative Binary Search: Found at position " << ans1 << endl;

    int ans2 = recursiveBinarySearch(arr, 0, n - 1, target);

    if(ans2 == -1)
        cout << "Recursive Binary Search: Not Found\n";
    else
        cout << "Recursive Binary Search: Found at position " << ans2 << endl;

    return 0;
}