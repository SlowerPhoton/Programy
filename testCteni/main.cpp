#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream soubor;
    soubor.open("ahoj.txt");

    soubor << "ahoj" << endl;

    soubor.close();

    soubor.open("ahoj.txt");
    string ahoj;

    soubor >> ahoj;

    cout << ahoj <<endl;
    return 0;
}
