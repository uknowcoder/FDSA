#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort
void bubbleSort(vector<int>& a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

// Selection Sort
void selectionSort(vector<int>& a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& a)
{
    int n = a.size();

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Print array
void printArray(vector<int>& a)
{
    for (int x : a)
        cout << x << " ";

    cout << endl;
}

int main()
{
    vector<int> marks = {72, 45, 90, 60, 30, 85};

    vector<int> a = marks;
    vector<int> b = marks;
    vector<int> c = marks;

    bubbleSort(a);
    cout << "Bubble Sort: ";
    printArray(a);

    selectionSort(b);
    cout << "Selection Sort: ";
    printArray(b);

    insertionSort(c);
    cout << "Insertion Sort: ";
    printArray(c);

    return 0;
}