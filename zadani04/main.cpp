#include <iostream>
#include <ctime>
#include <cstdlib>
#define velPole 20

using namespace std;

void tiskniPole(int pole[velPole]){
    for (int i = 0; i < velPole; i++)
        cout << pole[i] << ' ';
    cout << endl;
}

int main()
{
    srand(time(NULL));

    int pole[velPole];

    int i = 0;
    randomness:
    pole[i] = rand()%1000+1;
    i++;
    if (i < velPole) goto randomness;

    tiskniPole(pole);

    // bubble sort
    int j = 0;
    prochazejHoZnovuAZnovu:
    i = 0;
    projdiCelePole:
    if (pole[i] > pole[i+1])
    {
        int pom = pole[i];
        pole[i] = pole[i+1];
        pole[i+1] = pom;
    }
    i++;
    if (i < velPole-1-j) goto projdiCelePole;
    j++;
    if (j < velPole) goto prochazejHoZnovuAZnovu;

    tiskniPole(pole);

    return 0;
}
