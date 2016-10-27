#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream vstup;
    vstup.open("vstup.txt");

    ofstream output;
    output.open("output.txt");

    int pocetVstupu;
    vstup >> pocetVstupu;

    for(int i = 0; i < pocetVstupu; i++){

        int pocIngredience;
        vstup >> pocIngredience;


        int *ingredience;
        ingredience = new int[pocIngredience*2];

        int delka = 0;

        for(int j = 0; j < pocIngredience; j++){

            vstup >> ingredience[j*2];
            vstup >> ingredience[j*2+1];

            if(ingredience[j*2+1] > delka)
                delka = ingredience[j*2+1];

        }

        cout << "delka: " << delka << endl;

        int mx = 0;



        for(int k = 0; k < pocIngredience; k++){

            int meziA = 0;
            int meziB = 0;

            int pozA = ingredience[k*2];
            int pozB = ingredience[k*2+1];

            for(int l = 0; l < pocIngredience; l++){
                if(ingredience[l*2]<=pozA and ingredience[l*2+1]>=pozA)
                    meziA++;
                if(ingredience[l*2]<=pozB and ingredience[l*2+1]>=pozB)
                    meziB++;
            }

            if(meziA > mx)
                mx = meziA;

            if(meziB > mx)
                mx = meziB;
        }



        cout << mx << endl;
        output << mx << endl;

    }



    vstup.close();
    return 0;
}
