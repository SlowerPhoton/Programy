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
        int zastavek;
        vstup >> zastavek; cout << "zastavek: " << zastavek << endl;
        int vlaku = 0;
        int kde = 0;

        while(true){
            int kam;
            vstup >> kam;
            vlaku++;
            cout << "kam: " << kam << endl;

            if(kde + kam >= (zastavek - 1)){
                int spam;
                for(int j = (kde + 1); j < zastavek; j++)
                    vstup >> spam;
                break;
            }

            kde += kam;
            int spam;
            for(int j = 0; j < kam - 1; j++)
                vstup >> spam;


        }

        output << vlaku << endl;

    }


    output.close();
    vstup.close();
    return 0;
}
