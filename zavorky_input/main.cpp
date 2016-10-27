#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{   ifstream vstup;
    vstup.open("zadani.in");
    string zavorky;

    int pocetKol;
    vstup>>pocetKol;

    while(pocetKol>0){
        vstup>>zavorky;
        for(int i=0; i<zavorky.size(); i++)
        cout << zavorky[i];
        cout<<"a"<<endl;
        pocetKol--;
    }

    return 0;
}
