#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream vstup;
    vstup.open("html.txt");

    ofstream vystup;
    vystup.open("sinHTML.txt");

    bool del = false;
    char c;
    while ( vstup.get(c) )
    {
        if (c == '<')
        {
            del = true;
            continue;
        }
        else if (c == '>')
        {
            del = false;
            continue;
        }
        if ( !del )
            cout << c;
    }

    vstup.close();
    vystup.close();
    return 0;
}
