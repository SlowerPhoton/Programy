#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>



using namespace std;

void debugPole(int pole[][10], int rad, int sl){
    for (int i = 0; i < rad; i++){
        for(int j = 0; j < sl; j++){
            cout << pole[i][j] << "\t";
        }
        cout << endl;
    }
}


int main()
{
    ifstream vstup;
    vstup.open("vstup.txt");
    if(vstup == NULL) cout << "null inp";
    ofstream output;
    output.open("output.txt");

    if(output == NULL)
        cout << "null out";

    int pocetVstupu;
    vstup >> pocetVstupu;

    for(int cykl = 0; cykl < pocetVstupu; cykl++){
        cout << cykl << "/" << pocetVstupu-1 << endl;

        int rad, sl;
        vstup >> sl; vstup >> rad;

        if(rad == 0) cout <<"rad 0" << endl;
        if(sl == 0) cout <<"sl 0" << endl;

        int ohnu;
        vstup >> ohnu;

        int pole[sl][rad];
        for(int i = 0; i < sl; i++){
            for(int j = 0; j < rad; j++){
                pole[i][j] = INT_MAX;
            }
        }

        for(int i = 0; i < ohnu; i++){
            int x, y;
            vstup >> x;
            vstup >> y;

            pole[x][y] = -1;

        }

        // simulate burning in time
        int zeit = 0;
        bool change = true;
        while(change){
            change = false;
            for(int a = 0; a < sl; a++){
                for(int b = 0; b < rad; b++){

                    if (pole[r][s] == (zeit-1)){
                        change = true;
                        // check for its surroundings

                        if((r+1) < rad and pole[r+1][s] > zeit)
                            pole[r+1][s] = zeit;
                        if((r+1) < rad and (s+1) < sl and pole[r+1][s+1] > zeit)
                            pole[r+1][s+1] = zeit;
                        if((r+1) < rad and (s-1) >= 0 and pole[r+1][s-1] > zeit)
                            pole[r+1][s-1] = zeit;
                        if((r-1) >= 0 and (s-1) >= 0 and pole[r-1][s-1] > zeit)
                            pole[r-1][s-1] = zeit;
                        if((r-1) >= 0 and (s+1) < sl and pole[r-1][s+1] > zeit)
                            pole[r-1][s+1] = zeit;
                        if((r-1) >= 0 and pole[r-1][s] > zeit)
                            pole[r-1][s] = zeit;
                        if((s+1) < sl and pole[r][s+1] > zeit)
                            pole[r][s+1] = zeit;
                        if((s-1) >= 0 and pole[r][s-1] > zeit)
                            pole[r][s-1] = zeit;

                            if(cykl == 1){
                            for (int i = 0; i < rad; i++){
                                for(int j = 0; j < sl; j++){
                                    if(pole[i][j] == INT_MAX)
                                        cout << -2 << "\t";
                                    else
                                        cout << pole[i][j] << "\t";
                                }
                                cout << endl;
                            }

                            cout << endl;}

                    }

                }
            }

            zeit++;

        }

        output << zeit << endl;

    }




    vstup.close();
    output.close();

    return 0;
}
