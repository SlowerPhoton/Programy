#include <iostream>
#include <fstream>

using namespace std;

int main()
{   ifstream vstup;
    vstup.open("zadani.in");

    ofstream vystup;
    vystup.open("vysledek.txt");

    int pocetVRade=0;
    vstup>>pocetVRade;

    int hledam;
    vstup>>hledam;

    int poradiHledam;
    vstup>>poradiHledam;

    int pole[pocetVRade+1];
    int celkemVPoli=0;

    int i = 0;
    while(i<pocetVRade){
        int neco;
        vstup >> neco;

        if (neco==hledam){
            pole[celkemVPoli]=i+1;
            celkemVPoli++;
            }

        i++;
    }

    int zbytek = poradiHledam%celkemVPoli;
    if(zbytek!=0){
        int poradi=poradiHledam/celkemVPoli*pocetVRade;

        poradi+=pole[zbytek-1];


        vystup<<poradi;}
    else{
        int poradi=(poradiHledam/celkemVPoli-1)*pocetVRade;
        poradi+=pole[celkemVPoli-1];

        vystup<<poradi;}

    vstup.close();
    vystup.close();

    return 0;
}
