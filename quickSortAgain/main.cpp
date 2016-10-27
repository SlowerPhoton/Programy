#include <iostream>

using namespace std;

void quicksort (int pole[], int levaHranice, int pravaHranice)
{
    int pivIndex = (levaHranice+pravaHranice)/2;
    int piv = pole [ pivIndex ];

    int r = pravaHranice;
    int l = levaHranice;
    while (true)
    {
        while ( pole[r] > piv ) r--;
        while ( pole[l] < piv ) l++;

        if (l < r)
        {
            int pom = pole[r];
            pole[r] = pole[l];
            pole[l] = pom;
        }
        else
            break;
    }

    if ( (pivIndex - levaHranice) > 1 ) quicksort(pole, levaHranice, pivIndex);
    if ( (pravaHranice - pivIndex) > 1 ) quicksort(pole, pivIndex, pravaHranice);
}

int main()
{
    int pole[10] = {0, 6, 2, 3, 4, 8, 9, 2, 1, 10};
    quicksort(pole, 0, 9);

    for (int i = 0; i < 10; i++)
        cout << pole[i] << '\t';
    cout << endl;

    return 0;
}
