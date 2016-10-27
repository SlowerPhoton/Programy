#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream vstup;
    vstup.open("diakritika.txt");

    char c;
    while (vstup.get(c))
        cout << (int) c << ' ' << c << '\t';

    vstup.close();

    vstup.open("diakritika.txt");
    while (vstup.get(c))
    {
        if ()
    }

    vstup.close();

    return 0;
}
