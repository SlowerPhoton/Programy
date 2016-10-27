#include <iostream>
#include <fstream>

using namespace std;

struct clovek
{
    char jmeno[30], prijmeni[30];
    char rodneCislo[10];
} TCLOVEK;

void novyBinSoubor(char nazev[]){
    ofstream soubor;
    soubor.open(nazev, ios::binary);
    soubor.close();
}

void pridejNaKonec(char nazev[])
{
    ofstream soubor;
    soubor.open(nazev, ios::binary | ios::app);

    cin >> TCLOVEK.jmeno;
    cin >> TCLOVEK.prijmeni;
    cin >> TCLOVEK.rodneCislo;

    soubor.write((char*) &TCLOVEK, sizeof(TCLOVEK));

    soubor.close();
}

void vypisData(char nazev[])
{
    ifstream soubor;
    soubor.open(nazev, ios::binary);

    cout << "jmeno" << '\t' << "prijmeni" << '\t' << "datum narozeni" << '\t' << endl;

    while (soubor.read((char*) &TCLOVEK, sizeof(TCLOVEK)))
    {
        cout << TCLOVEK.jmeno << '\t';
        cout << TCLOVEK.prijmeni << '\t';
        cout << TCLOVEK.rodneCislo[4] << TCLOVEK.rodneCislo[5] << "."; // dd
        if (TCLOVEK.rodneCislo[2] > '1') TCLOVEK.rodneCislo[2] -= 5;
        cout << TCLOVEK.rodneCislo[2] << TCLOVEK.rodneCislo[3] << "."; // mm
        if (TCLOVEK.rodneCislo[0] <= '1')
            cout << "20" << TCLOVEK.rodneCislo[0] << TCLOVEK.rodneCislo[1] << endl;
        else
            cout << "19" << TCLOVEK.rodneCislo[0] << TCLOVEK.rodneCislo[1] << endl;
    }

    soubor.close();
}

int main()
{
    //novyBinSoubor("binSoubor.dat");
    pridejNaKonec("binSoubor.dat");
    //vypisData("binSoubor.dat");
    //vypisData("binSoubor.dat");
    pridejNaKonec("binSoubor.dat");
    vypisData("binSoubor.dat");
    return 0;
}
