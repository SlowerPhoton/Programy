#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "Vitej v zabavne hre s cisly!" << endl;


    cout << "Jake je N?" << endl;
    int pocetCisel; cin >> pocetCisel;

    cout << "Jake je k?" << endl;
    int k; cin >> k;

    cout << "Zadej cisla na kamenech, jedno po druhem: " << endl;
    int kameny[pocetCisel];
    for(int i = 0; i < pocetCisel; i++){
        cout << "> ";
        cin >> kameny[i];
    }


    cout << "Nyni muzes hrat!" << endl;


        for(int i = 0; i < pocetCisel; i++)
            cout << kameny[i] << " ";
        cout << endl;

    for(int a = 0; a < 1000000; a++){

        //cout << "> ";
        int tah;
        // cin >> tah;
        tah = rand()%pocetCisel+1;

        if(tah > pocetCisel or tah < 0)
            continue;

        int staraPoloha;
        for(staraPoloha = 0; staraPoloha < pocetCisel; staraPoloha++){
            if(kameny[staraPoloha] == tah)
                break;
        }
        int novaPoloha = (staraPoloha - k + pocetCisel - 1)%pocetCisel;
        for (int i = staraPoloha; i != novaPoloha; i = (i+1)%pocetCisel){
            kameny[i] = kameny[(i+1)%pocetCisel];
        }
        kameny[novaPoloha] = tah;

        /// najdi 1
        int i;
        for(i = 0; i < pocetCisel; i++){
            if(kameny[i] == 1)
                break;
        }

        for(int j = 0; j < pocetCisel; j++){
            if((kameny[(i+j)%pocetCisel])%pocetCisel + 1 != kameny[(i+j+1)%pocetCisel]){
                i = -1;
                break;
            }
        }

        /// vypis pole
        /*for(int j = 0; j < pocetCisel; j++,i = (i+1)%pocetCisel)
            cout << kameny[i] << " ";
        cout << endl;*/

        if(i != -1){
            for(int j = 0; j < pocetCisel; j++,i = (i+1)%pocetCisel)
            cout << kameny[i] << " ";
            cout << endl;
            break;
        }

    }

    return 0;
}
