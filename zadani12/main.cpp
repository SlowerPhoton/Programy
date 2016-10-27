#include <iostream>
#include <fstream>

using namespace std;

struct word
{
    string s;
    int amount = 1;
    word *next;
};

word *beginning = NULL;

void pridejDoSeznamu(string s)
{
    word *pom;
    pom = new word;

    pom->s = s;
    pom->next = beginning;
    beginning = pom;
}

// returns true if a duplication, returns false otherwise
bool duplikace(string s)
{
    if (beginning == NULL)
        return false;

    word *pom = beginning;
    while (true)
    {
        if (pom->s == s)
        {
            pom->amount++;
            return true;
        }
        if (pom->next != NULL) pom = pom->next;
        else return false;
    }
}

void tiskniSeznam ()
{
    if (beginning == NULL)
        return;

    word *pom = beginning;
    while (true)
    {
        cout << pom->s << '\t' << pom->amount << endl;
        if (pom->next != NULL) pom = pom->next;
        else return;
    }
}

int main()
{
    ifstream zprava;
    zprava.open("zprava.txt");

    string nextWord;
    while (zprava >> nextWord)
    {
        if ( duplikace(nextWord) == false)
            pridejDoSeznamu(nextWord);
    }

    zprava.close();

    tiskniSeznam();

    return 0;
}
