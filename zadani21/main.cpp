#include <iostream>
#include <fstream>

using namespace std;

struct{
    char prijmeni[30], jmeno[30];
    char stat[3];
    int cas;
} TZAVODNIK;

void novySoubor ()
{
    cout << "Jste si orpavdu jisti? [A/N] ";
    char a; cin >> a;
    if (a == 'N' or a == 'n') return;
    ofstream bin;
    bin.open("zavodnici.data", ios::binary | ios::out);
    bin.close();
}

void pridejZavodnika(){
    cout << "Jmeno: " << endl; cin >> TZAVODNIK.jmeno;
    cout << "Prijmeni: " << endl; cin >> TZAVODNIK.prijmeni;
    cout << "Stat: " << endl; cin >> TZAVODNIK.stat;
    TZAVODNIK.cas = -1;
    ofstream bin;
    bin.open("zavodnici.data", ios::binary | ios::app);

    bin.write((char*) &TZAVODNIK, sizeof(TZAVODNIK));

    bin.close();
}

void vypisVsechZavodniku()
{
    ifstream bin;
    bin.open("zavodnici.data", ios::binary | ios::in);

    cout << "Jmeno" << "\t" << "Prijmeni" << "\t" << "Stat" << "\t" << "Cas" << endl;
    while ( bin.read((char*) &TZAVODNIK, sizeof(TZAVODNIK)) )
    {
        cout << TZAVODNIK.jmeno << '\t' << TZAVODNIK.prijmeni << '\t' << TZAVODNIK.stat << '\t'  << TZAVODNIK.cas << endl;
    }

    bin.close();
}

void zmenaCasu()
{
    fstream bin;
    bin.open("zavodnici.data", ios::binary | ios::in | ios::out);

    int poradi;
    cout << "Poradi: "; cin >> poradi;

    cout << "Jmeno" << "\t" << "Prijmeni" << "\t" << "Stat" << "\t" << "Cas" << endl;
    int i = 0;
    while ( bin.read((char*) &TZAVODNIK, sizeof(TZAVODNIK)) )
    {
        if (i == poradi) break;
        i++;
        cout  << "tellg " << bin.tellg() << endl;
    }
    cout << TZAVODNIK.jmeno << '\t' << TZAVODNIK.prijmeni << '\t' << TZAVODNIK.stat << '\t'  << TZAVODNIK.cas << endl;
    cout << "Prejete si zmenit cas u tohoto zavodnika? [A/N] ";
    char a; cin >> a;
    if (a == 'n' or a == 'N') return;

    cout << "Novy cas: ";
    cin >> TZAVODNIK.cas;

    bin.seekp( bin.tellg() - sizeof(TZAVODNIK), ios::beg );
    //cout << bin.tellp() << endl;
    bin.write((char*) &TZAVODNIK, sizeof(TZAVODNIK));

    bin.close();
}

int main()
{

    int inp;
    do
    {
        cout << "1" << '\t' << "Pridani noveho zavodnika" << endl;
        cout << "2" << '\t' << "Vypis vsech zavodniku" << endl;
        cout << "3" << '\t' << "Zadani casu pro lib. zavodnika" << endl;
        cout << "4" << '\t' << "Vytvoreni prazdneho souboru zavodniku" << endl;
        cout << "5" << '\t' << "Konec programu" << endl;
        cin >> inp;
        switch (inp)
        {
            case 5: break;
            case 4: novySoubor();
                    break;
            case 1: pridejZavodnika();
                    break;
            case 2: vypisVsechZavodniku();
                    break;
            case 3: zmenaCasu();
                    break;
        }
    } while (inp != 5);


    return 0;
}
