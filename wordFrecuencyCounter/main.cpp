#include <iostream>
#include <cstring>

using namespace std;

struct alpha
{
    int number = 0;
    alpha *below[26];
};

alpha *beg = NULL;

void addWord (string word)
{
    alpha *hlpr = beg;
    for (int i = 0; i < word.length(); i++)
    {
        if (hlpr->below [ word[i] - 'a' ] == NULL)
        {
            hlpr->below [ word[i] - 'a' ] = new aplha;
            for (int i = 0; i < 26; i++)
            {
                hlpr->below [ word[i] - 'a' ]->below[i] = NULL;
            }
        }
        hlpr = hlpr->below [ word[i] - 'a' ];
    }
    hlpr->number++;
}

int main()
{
    // create the first step
    beg = new aplha;
    for (int i = 0; i < 26; i++)
    {
        beg->below[i] = NULL;
    }

    return 0;
}
