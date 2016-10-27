#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char input[16];

    cout << "cin: ";
    int cislo;
    cin >> cislo;

    /*cout << "fgets: ";
    fgets(input, 16, stdin);*/

    cin.clear(); cin.ignore(INT_MAX,'\n');

    char gts[20];
    cout << "gets: ";
    gets(gts);


    cout << "cin: " << cislo << endl;
    //cout << "fgets: " << input << endl;
    cout << "gets: " << gts << endl;
    return 0;
}
