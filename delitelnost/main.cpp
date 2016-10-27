#include <iostream>
#include <fstream>
#include <cmath>
#include <limits.h>

using namespace std;

int urciPocetDelitelu(int cislo){

    int pd = 0;
    int root = sqrt(cislo);

    for (int i = 2; i <= root; i++){
        if (cislo % i == 0)
            pd++;
    }

    return pd;
}

int main()
{
    string vstupName = "5D.txt";

    ifstream inp;
    inp.open(vstupName.c_str());

    int maxPD = 0;
    int aktMaxPDNum;

    unsigned int nejm = UINT_MAX;

    int cislo;
    while (inp >> cislo){
        int pd = urciPocetDelitelu(cislo);
        if (pd > maxPD){
            maxPD = pd;
            aktMaxPDNum = cislo;
        }
        if (pd == maxPD){
            if (cislo < aktMaxPDNum)
                aktMaxPDNum = cislo;
        }

        if (cislo < nejm)
            nejm = cislo;
    }

    cout << "nejvetsi pocet delitelu ma: " << aktMaxPDNum << endl;

    /// mame nejmensi cislo, zkontroluj jestli deli vsechna ostatni cisla
    inp.close();
    inp.open(vstupName.c_str());
    bool deli = true;
    while (inp >> cislo){
        if (cislo % nejm != 0){
            deli = false;
            break;
        }
    }
    inp.close();
    cout << "cislo, ktere beze zbytku deli vsechna ostatni";
    if (!deli)
        cout << " neni obsazeno" << endl;
    else
        cout << ": " << nejm << endl;

    return 0;
}
