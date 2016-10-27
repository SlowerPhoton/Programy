#include <iostream>
#include <fstream>
#include <cmath> //abs

#define RADKU 3
#define SLOUPCU RADKU+1

using namespace std;

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

/// pozn.: vzhledem k tomu, ze ihned pouzivam nejnovejsi vysledky dal, je to vlastne Gauss-Seidel
void jacobi (double matice[RADKU][SLOUPCU], double reseni[RADKU], double presnost)
{
    /// prvne je potreba si matici pripravit
    double uprMatice[RADKU][SLOUPCU]; // sem ulozime upravenou matici
    for (int r = 0; r < RADKU; r++)
    {
        double diag = matice[r][r];
        for (int s = 0; s < SLOUPCU - 1; s++)
        {
            uprMatice[r][s] = matice[r][s] / (-diag);
        }
        uprMatice[r][SLOUPCU-1] = matice[r][SLOUPCU-1] / diag;
    }

    /// "tipneme si" reseni, napriklad nulovy vektor
    for (int i = 0; i < RADKU; i++)
    {
        reseni[i] = 0;
    }

    /// zpresnujeme tak dlouho, dokud abs(stare vysledky - nove vysledky) > presnost
    double starexn;
    do
    {
        for (int r = 0; r < RADKU; r++)
        {
            double suma = 0;
            for (int s = 0; s < SLOUPCU - 1; s++)
            {
                // pokud diagonalni, preskoc
                if ( s == r ) continue;
                suma += uprMatice[r][s]*reseni[s];
            }
            // pricti konstantni prvek
            suma += uprMatice[r][SLOUPCU-1];
            if (r == RADKU-1) starexn = reseni[r];
            reseni[r] = suma;
        }
    } while ( fabs(starexn - reseni[RADKU-1]) > presnost );
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
    nactiMatici(matice, "video.txt");
    tiskniMatici(matice);

    double reseni[RADKU];
    jacobi(matice, reseni, 0.001);
    tiskniReseni(reseni);

    return 0;
}
