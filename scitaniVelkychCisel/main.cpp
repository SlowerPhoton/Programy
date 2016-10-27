#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    cout << "Zadej dve cisla k secteni, mohou byt az 100ciferne" << endl;

    char cislo1[101];
    char cislo2[101];

    cin >> cislo1;
    cin >> cislo2;
    cout << endl;

    char vysledek[200];

    int a[101];
    for(int i = 0; i < 101; i++)
        a[i] = 0;
    for(int i = 0, n = strlen(cislo1); i < n; i++){
        a[i] = cislo1[n-i-1] - '0';
        //cout << (int) a[i];
    }
    //cout << endl;

    int b[101];
    for(int i = 0; i < 101; i++)
        b[i] = 0;
    for(int i = 0, n = strlen(cislo2); i < n; i++){
        b[i] = cislo2[n-i-1] - '0';
        //cout << (int) b[i];
    }


    int polohaVysledek = 0;

    int kolikratCyklit;
    if(strlen(cislo1) > strlen(cislo2))
        kolikratCyklit = strlen(cislo1);
    else
        kolikratCyklit = strlen(cislo2);

    int zbytekZMinule = 0;
    for(int i = 0; i < kolikratCyklit; i++){

        int mezivypocet = zbytekZMinule + a[i] + b[i];
        zbytekZMinule = 0;
        if(mezivypocet > 9){
            zbytekZMinule = 1;
            mezivypocet -= 10;
        }
        vysledek[polohaVysledek] = mezivypocet;
        polohaVysledek++;
    }
    if(zbytekZMinule == 1) {
        vysledek[polohaVysledek] = zbytekZMinule;
        vysledek[++polohaVysledek] = '/0';
    }
    else
        vysledek[polohaVysledek] = '\0';

    /*cout << endl << "strlen " << strlen(vysledek) << endl;
    cout << endl << "polohaVysledek " << polohaVysledek-1 << endl;*/

    //cout << endl << endl;
    for(int n = polohaVysledek - 1/*strlen(vysledek) - 1*/; n >= 0; n--)
        cout << (int) vysledek[n];
    return 0;
}
