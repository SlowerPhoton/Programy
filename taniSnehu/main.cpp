#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream vstup;
    vstup.open("vstup.txt");
    ofstream output;
    output.open("output.txt");

    int pocetZadani; vstup >> pocetZadani;

    for(int cykl = 0; cykl < pocetZadani; cykl++){
        int sl; vstup >> sl;

        int *snih;
        snih = new int[sl];

        for(int i = 0; i < sl; i++)
            vstup >> snih[i];

        int zarazka1, zarazka2;

        for(int i = 0; i < sl - 1; i++){
            if(snih[i] >= snih[i+1]){
                zarazka1 = i;
                break;
            }
        }

        for(int i = sl - 1; i > 1; i--){
            if(snih[i] >= snih[i-1]){
                zarazka2 = i;
                break;
            }
        }

        int pamatuj = 0;
        int zac = 0, kon = sl - 1;

        int zeit = 0;
        while(zeit<=0){

            // umaz po zarazky
            int pom = snih[zac];
            snih[zac] = 0;
            for(int i = zac + 1; i <= zarazka1; i++){
                int a = snih[i];
                snih[i] = pom;
                snih[i]--;
                pom = a;
            }
            while(snih[zac]==0)zac++;

            pom = snih[kon];
            snih[kon] = 0;
            for(int i = kon - 1; i >= zarazka2; i--){
                int a = snih[i];
                snih[i] = pom;
                snih[i]--;
                pom = a;
            }
            while(snih[kon]==0)kon--;

            // sniz pamatuj
            pamatuj++;

            // najdi nove zarazky


            zeit++;
        }
        /*debug*/
        for(int i = 0; i < sl; i++)
            cout << snih[i] << " ";
        cout << endl;

        output << zarazka1 << " " << zarazka2 << endl;

    }


    vstup.close();
    output.close();
    return 0;
}
