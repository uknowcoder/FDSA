#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int items[100];

    cout << "Enter items: ";
    for(int i = 0; i < n; i++)
    {
        cin >> items[i];
    }

    int h;
    cout << "Enter hours: ";
    cin >> h;

    h = h % n;

    for(int i = 0; i < h; i++)
    {
        int first = items[0];

        for(int j = 0; j < n - 1; j++)
        {
            items[j] = items[j + 1];
        }

        items[n - 1] = first;
    }

    cout << "Final order: ";
    for(int i = 0; i < n; i++)
    {
        cout << items[i] << " ";
    }

    return 0;
}