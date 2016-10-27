#include <iostream>

using namespace std;

struct tprvek{
    int hodnota;
    struct tprvek *dalsi;
} TPRVEK;

tprvek *zacatek = NULL;

void tiskniSeznam()
{
    tprvek *pom = zacatek;
    while (pom != NULL)
    {
        cout << pom->hodnota << '\t';
        pom = pom->dalsi;
    }
    cout << endl;
}

void pridejprvek(int hodnota)
{
    tprvek *pom = zacatek;
    if (pom == NULL or pom->hodnota >= hodnota)
    {
        tprvek *n;
        n = new tprvek;
        n->hodnota = hodnota;
        n->dalsi = zacatek;
        zacatek = n;
        return;
    }

    while (pom->dalsi!=NULL and pom->dalsi->hodnota < hodnota)
    {
        pom = pom->dalsi;
    }
    if (pom->dalsi == NULL)
    {
        tprvek *n;
        n = new tprvek;
        n->hodnota = hodnota;
        n->dalsi = NULL;
        pom->dalsi = n;
    }
    else
    {
        tprvek *n;
        n = new tprvek;
        n->hodnota = hodnota;
        n->dalsi = pom->dalsi;
        pom->dalsi = n;
    }
}

int main()
{
    int i;
    while (true)
    {
        cin >> i; if (i == -1) break;
        pridejprvek(i);
        tiskniSeznam();
    }
    return 0;
}
