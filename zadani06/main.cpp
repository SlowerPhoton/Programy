#include <iostream>
#include <fstream>

using namespace std;

void nactiMatici(char nazev[], int matice[5][5])
{
    ifstream vstup;
    vstup.open(nazev);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <5; j++)
            vstup >> matice[i][j];
    }

    vstup.close();
}

void sectiMatice(int matice1[5][5], int matice2[5][5], int vysledek[5][5])
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j <5; j++)
            vysledek[i][j] = matice1[i][j] + matice2[i][j];
}

void tiskniMatici(int matice[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <5; j++)
            cout << matice[i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}

void ulozMatici(char nazev[], int matice[5][5])
{
    ofstream vystup;
    vystup.open(nazev);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <5; j++)
            vystup << matice[i][j] << '\t';
        vystup << endl;
    }

    vystup.close();
}

int main()
{
    int matice1[5][5];
    nactiMatici("maticea.txt", matice1);
    int matice2[5][5];
    nactiMatici("maticeb.txt", matice2);

    int vysledek[5][5];
    sectiMatice(matice1, matice2, vysledek);

    /*
    tiskniMatici(matice1);
    tiskniMatici(matice2);
    tiskniMatici(vysledek);
    */

    ulozMatici("maticec.txt", vysledek);

    return 0;
}
