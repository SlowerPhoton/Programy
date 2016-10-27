#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream vstup;
    vstup.open("spatnemezery.txt");

    ofstream vystup;
    vystup.open("nbsp.txt");

    char c;
    int wordLength = 0;
    while ( vstup.get(c) )
    {
        if ( (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') )
        {
            wordLength++;
        }
        else if (c == ' ' and wordLength == 1)
        {
            wordLength = 0;
            vystup << "&nbsp";
            continue;
        }
        else
            wordLength = 0;
        vystup << c;
    }

    vstup.close();
    vystup.close();

    return 0;
}
