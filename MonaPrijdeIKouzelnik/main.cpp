#include <iostream>
#include <fstream>

using namespace std;

void kouzlo1(int kralici[], int N){
    int *pom;
    pom = new int[N];

    for(int i = 0; i < N; i++){
        pom[N-i-1] = kralici[i];
    }

    for(int i = 0; i < N; i++){
        kralici[i] = pom[i];
    }

    delete[] pom;
}


int main()
{
    ifstream vstup;
    vstup.open("vstup1.txt");

    ofstream output;
    output.open("output.txt");

    int pocetVstupu;
    vstup >> pocetVstupu;

    for(int cykl = 0; cykl < pocetVstupu; cykl++){
        cout << cykl << "/" << pocetVstupu << endl;

        int N, K, P;
        vstup >> N; vstup >> K; vstup >> P;

        int *kralici;
        kralici = new int[N];

        bool direction = true;
        for(int i = 0; i < N; i++){
            vstup >> kralici[i];
        }

        for(int i = 0; i < K; i++){
            int kouzlo;
            vstup >> kouzlo;

            if(kouzlo == 1){
                //kouzlo1(kralici, N);
                direction = !direction;
            }

            else {
                int pom = kralici[0];
                kralici[0] = kralici[N-1];
                kralici[N-1] = pom;
            }


        }

        /*for(int i = 0; i < N; i++)
            cout << kralici[i] << " ";*/

        if(!direction)
            kouzlo1(kralici, N);

        for(int i = 0; i < P; i++){
            int tisk;
            vstup >> tisk;

            output << kralici[tisk-1] << " ";
        }

        output << endl;

        delete[] kralici;

    }

    vstup.close();
    output.close();

    return 0;
}
