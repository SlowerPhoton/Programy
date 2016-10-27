#include <iostream>
#include <fstream>

using namespace std;

void nactiCislo(string nazev, string *cislo){
    ifstream vstup;
    vstup.open(nazev.c_str());
    vstup >> *cislo;
}

void tiskniCislo(char cislo[]){
    cout << 0;
    for (int i = 0; i < 100; i++){
        cout << (int) cislo[i];
    }
    cout << endl;
}

void tiskniVysledek(char vysledek[]){
    for (int i = 0; i < 101; i++){
        cout << (int) vysledek[i];
    }
    cout << endl;
}

void stringToArray(string vstup, char cislo[100]){
    int n = vstup.length();
    for (int i = 0; i < 100-n; i++)
        cislo[i] = 0;
    for (int i = 0, n = vstup.length(); i < n; i++){
        cislo[i+100-n] = vstup[i] - '0';
    }
}

void sectiArray(char cislo1[100], char cislo2[100], char vysledek[101]){

    int zbytek = 0;
    for(int i = 99; i >= 0; i--){
        int mezivysledek = cislo1[i] + cislo2[i] + zbytek;
        zbytek = mezivysledek/10;
        mezivysledek %= 10;
        vysledek[i+1] = mezivysledek;
    }
    vysledek[0] = zbytek;

}

int main()
{
    string cislo1s;
    nactiCislo("cislo1.txt", &cislo1s);

    char cislo1[100];
    stringToArray(cislo1s, cislo1);

    string cislo2s;
    nactiCislo("cislo2.txt", &cislo2s);

    char cislo2[100];
    stringToArray(cislo2s, cislo2);


    tiskniCislo(cislo1);
    tiskniCislo(cislo2);

    char vysledek[101];
    sectiArray(cislo1, cislo2, vysledek);
    tiskniVysledek(vysledek);


    return 0;
}
