#include <iostream>

using namespace std;

int main()
{
    string word;
    bool palindrome;

    cout << "Enter a string:\n";
    getline(cin, word);

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == ' ')
        {
            word.erase(i, 1);
        }
    }

    for (int i = 0; i < word.size()/2; i++)
    {
        if (word[i] != word[word.size() - i - 1])
        {
            palindrome = false;
            break;
        }
        palindrome = true;
    }

    cout << palindrome;
}