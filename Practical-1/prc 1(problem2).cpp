#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of borrow records: ";
    cin >> n;

    int books[100];

    cout << "Enter book IDs: ";
    for(int i = 0; i < n; i++)
    {
        cin >> books[i];
    }

    bool found = false;

    cout << "\nBooks borrowed more than once:\n";

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(books[i] == books[j])
            {
                count++;
            }
        }

        if(count > 1)
        {
            int k;

            for(k = 0; k < i; k++)
            {
                if(books[k] == books[i])
                {
                    break;
                }
            }

            if(k == i)
            {
                cout << books[i] << endl;
                found = true;
            }
        }
    }

    if(found == false)
    {
        cout << "No duplicate book IDs found." << endl;
    }

    return 0;
}