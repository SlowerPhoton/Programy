#include <iostream>
#define POCET_PRVKU 9

using namespace std;

void tiskniPole(int pole[], size_t velikost);

// hranice jsou vcetne
void quickSort(int pole[], size_t levaHranice, size_t pravaHranice){
    size_t pivot = (levaHranice + pravaHranice)/2; // poloha pivota
    size_t l = levaHranice;
    size_t r = pravaHranice;

    while (true)
    {
        while (pole[l] < pole[pivot]) l++;

        while (pole[r] > pole[pivot]) r--;

        if (l < r)
        {
            // prohod prvky mezi sebou
            int pom = pole[l];
            pole[l] = pole[r];
            pole[r] = pom;
        }
        else
            break;
    }

    tiskniPole(pole, POCET_PRVKU);

    if ( (pivot - levaHranice) > 1) quickSort(pole, levaHranice, pivot);
    if ( (pravaHranice - pivot) > 1) quickSort(pole, pivot, pravaHranice);

}

void tiskniPole(int pole[], size_t velikost){
    for (size_t i = 0; i < velikost; i++)
        cout << pole[i] << ' ';
    cout << endl;
}

int main()
{
    int pole[] = {1, 2, 3, 4, 10, 5, 6, 7, 8};

    quickSort(pole, 0, POCET_PRVKU-1);

    tiskniPole(pole, POCET_PRVKU);

    return 0;
}
