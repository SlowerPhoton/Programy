#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void naplnPole(int pole[]){
    for (int i = 0; i < 25; i++)
        pole[i] = rand()%100;
}

void setridPole(int pole[])
{
    for (int i = 0; i < 24; i++)
        for (int j = 0; j < 24-i; j++)
            if (pole[j] > pole[j+1])
            {
                int pom = pole[j];
                pole[j] = pole[j+1];
                pole[j+1] = pom;
            }
}

void tiskniPole(int pole[])
{
    for (int i = 0; i < 25; i++)
        cout << pole[i] << '\t';
    cout << endl;
}

// returns false if not found, 1 otherwise
bool najdiPrvek(int pole[], int cislo)
{
    int levaHranice = 0;
    int pravaHranice = 24;

    while(levaHranice < pravaHranice - 1)
    {
        int stred = pole[(levaHranice+pravaHranice)/2];
        if (stred == cislo)
            return true;
        else if (stred < cislo)
            levaHranice = (levaHranice+pravaHranice)/2;
        else
            pravaHranice = (levaHranice+pravaHranice)/2;
        cout << "L" << levaHranice << "\t" << "R" << pravaHranice << endl;
    }
    return false;
}

int main()
{
    int pole[25];
    naplnPole(pole);
    tiskniPole(pole);
    setridPole(pole);
    tiskniPole(pole);
    while (true)
    {
        int cislo;
        cin >> cislo;
        cout << najdiPrvek(pole, cislo) << endl;
    }
    return 0;
}
