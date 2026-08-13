#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;

    cout << "Enter sentence: ";
    getline(cin, sentence);

    string word = "";
    string longest = "";
    int maxLength = 0;

    for(int i = 0; i <= sentence.length(); i++)
    {
        if(sentence[i] != ' ' && sentence[i] != '\0')
        {
            word = word + sentence[i];
        }
        else
        {
            if(word.length() > maxLength)
            {
                maxLength = word.length();
                longest = word;
            }

            word = "";
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << maxLength << endl;

    return 0;
}