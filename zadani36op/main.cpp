#include <iostream>

using namespace std;

struct tprvek{
    int hodnota;
    struct tprvek *dalsi;
};

tprvek *zacatek = NULL;

void tiskni ()
{
    tprvek *pom = zacatek;
    while (pom != NULL)
    {
        cout << pom->hodnota << '\t';
        pom = pom->dalsi;
    }
    cout << endl;
}

void pridej (int cislo)
{
    tprvek *pom = zacatek;

    if (pom == NULL or pom->hodnota >= cislo)
    {
        pom = new tprvek;
        pom->hodnota = cislo;
        pom->dalsi = NULL;
        zacatek = pom;
        return;
    }
    if (pom->dalsi == NULL)
    {
        if (pom->hodnota < cislo)
        {
            pom->dalsi = new tprvek;
            pom->dalsi->hodnota = cislo;
            pom->dalsi->dalsi = NULL;

        }
        else
        {
            tprvek *pom2;
            pom2 = new tprvek;
            pom2->hodnota = cislo;
            pom2->dalsi = pom;
            zacatek = pom2;
        }
        return;
    }

    while (pom->dalsi != NULL)
    {
        if (pom->dalsi->hodnota > cislo)
        {
            tprvek *pom2;
            pom2 = new tprvek;
            pom2 -> hodnota = cislo;
            pom2 -> dalsi = pom->dalsi;
            pom->dalsi = pom2;
            return;
        }
        pom = pom->dalsi;
    }

    tprvek *pom2;
    pom2 = new tprvek;
    pom2 -> hodnota = cislo;
    pom2 -> dalsi = NULL;
    pom->dalsi = pom2;
}

int main()
{
    while (true)
    {
        int i; cin >> i;
        pridej(i);
        tiskni();
    }
    return 0;
}
