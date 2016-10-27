#include <iostream>

using namespace std;

int main()
{
    cout << "Zadej pocet poschodi, pokoju na poschodi a prichozich hostu" << endl;

    // pocet poschodi
    int p;
        cout << "pocet poschodi: ";
        cin >> p;

    // pocet pokoju na poschodi
    int n;
        cout << "pocet pokoju na poschodi: ";
        cin >> n;

    // pocet prichozich hostu na poschodi
    int h;
        cout << "pocet prichozich hostu: ";
        cin >> h;

    // kolik hostu jsme schopni ubytovat?
    int maxHostu = 0;


    unsigned int hotel[h];

    // pro kazdeho hosta
    for(int i = 0; i < h; i++){

        // nacti vysku
        int v;
            cout << "vyska hosta cislo " << i + 1 << ": ";
            cin >> v;


        while(1){

            // zkontroluj zda pokoje na patre jeho vysky uz nejsou plne
            int pocet = n;
            for(int k = 0; k < i; k++){
                if(hotel[k] == v) pocet--;
            }

            // pokud jsou plne, sniz mu vysku o 1
            if(pocet <= 0){
               // cout << "ajajaj" << endl;
                v--;
                // pokud je vyska nizsi nez 1, uz nemuzeme hosta ubytovat
                if(v < 1){
                    // nechceme tuto promennou prepisovat, kdyz nebudeme schopni ubytovat i dalsiho hosta
                    if(maxHostu == 0) maxHostu = i;
                    break;
                }
            }
            // pokud ne, ukonci cyklus
            else
                break;
        }

        // vloz cislo jeho patra do hotelu - vyska v tuto chvili odpovida cislu jeho patra
        hotel[i] = v;

    }

    // pokud se behem cyklu maxHostu nezmenilo, vsichni byli ubytovani
    if(maxHostu == 0)
        maxHostu = h;

    // vypis, ve kterych podlazi bydli hosti, ktere se nam podarilo ubytovat
    cout << maxHostu << endl;
    for(int i = 0; i < maxHostu; i++){
        cout << "\t" << hotel[i];
    }
    cout << endl;



    return 0;
}
