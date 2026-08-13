#include <iostream>
using namespace std;

// Iterative Linear Search
int iterativeSearch(string arr[], int n, string target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// Recursive Linear Search
int recursiveSearch(string arr[], int n, string target, int index)
{
    if(index == n)
    {
        return -1;
    }

    if(arr[index] == target)
    {
        return index;
    }

    return recursiveSearch(arr, n, target, index + 1);
}

int main()
{
    int n;

    cout << "Enter number of license plates: ";
    cin >> n;

    string arr[n];

    cout << "Enter license plates:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    string target;

    cout << "Enter target license plate: ";
    cin >> target;

    int ans1 = iterativeSearch(arr, n, target);

    if(ans1 == -1)
        cout << "Iterative Search: Not Found\n";
    else
        cout << "Iterative Search: Found at position " << ans1 << endl;

    int ans2 = recursiveSearch(arr, n, target, 0);

    if(ans2 == -1)
        cout << "Recursive Search: Not Found\n";
    else
        cout << "Recursive Search: Found at position " << ans2 << endl;

    return 0;
}