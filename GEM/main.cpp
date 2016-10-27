#include <iostream>
#include <fstream>
#include <cmath> //abs

#define RADKU 3
#define SLOUPCU RADKU+1

using namespace std;

/// Gauss Elimination Method

void nactiMatici(double matice[RADKU][SLOUPCU], char *nazev)
{
    ifstream vstup;
    vstup.open(nazev);

    for (int r = 0; r < RADKU; r++)
        for (int s = 0; s < SLOUPCU; s++)
            vstup >> matice[r][s];

    vstup.close();
}

void tiskniMatici(double matice[RADKU][SLOUPCU])
{
    for (int r = 0; r < RADKU; r++)
    {

        for (int s = 0; s < SLOUPCU; s++)
            cout << matice[r][s] << '\t';
        cout << endl;
    }
    cout << endl;
}

void vynasobAPricti (double matice[RADKU][SLOUPCU], int rh, int r, int s)
// rh oznacuje hlavni radek, ktery nuluje ostatni
// r oznacuje radek, ktery bude vynulovan tim hlavnim
// s oznacuje, ve kterem sloupci chceme 0
{
    double k = matice[rh][s]/matice[r][s];
    matice[r][s] = 0;
    for (int sl = s+1; sl < SLOUPCU; sl++)
    {
        matice[r][sl] = matice[r][sl]*k - matice[rh][sl];
    }
}

void nulujMatici (double matice[RADKU][SLOUPCU])
{
    for (int s = 0; s < SLOUPCU-1; s++)
    {
        for (int r = 1+s; r < RADKU; r++)
        {
            vynasobAPricti(matice, s, r, s);
        }
    }
}

void zjistiReseni (double matice[RADKU][SLOUPCU], double reseni[RADKU])
{
    for (int r = RADKU-1; r >= 0; r--)
    {
        double sum = 0;
        for (int s = RADKU-1; s > r; s--)
        {
            sum += matice[r][s]*reseni[s];
        }
        reseni[r] = (matice[r][SLOUPCU-1] - sum)/matice[r][r];
    }
}

void tiskniReseni(double reseni[RADKU])
{
    for (int i = 0; i < RADKU; i++)
        cout << "x" << i+1 << " = " << reseni[i] << endl;
    cout << endl;
}

int main()
{
    double matice[RADKU][SLOUPCU];
    nactiMatici(matice, "prezentace.txt");
    tiskniMatici(matice);

    nulujMatici(matice);
    tiskniMatici(matice);

    double reseni[RADKU];
    zjistiReseni(matice, reseni);
    tiskniReseni(reseni);


    return 0;
}
