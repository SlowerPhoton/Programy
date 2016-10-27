#include <iostream>
#include <fstream>
#include <graphics.h>

using namespace std;

int main()
{
    string vstupName = "1K.txt";

    ifstream inp;
    inp.open(vstupName.c_str());

    string radek;
    int radku = 0;
    while (inp >> radek){
        radku++;
    }
    bool pole[radku][radek.length()];
    inp.close();

    inp.open(vstupName.c_str());
    for (int row = 0; row < radku; row++){
        inp >> radek;
        for (int i = 0, n = radek.length(); i < n; i++){
            if (radek[i] == '0')
                pole[row][i] = 0;
            else
                pole[row][i] = 1;
        }
    }
    inp.close();

 /*   for (int row = 0; row < radku; row++){
        for (int col = 0; col < radek.length(); col++)
            cout << pole[row][col];
        cout << endl;
    }*/

    int pocetCtvercu = 0;
    for (int row = 0; row < radku; row++)
    {
        for (int col = 0; col < radek.length(); col++)
        {
            // pokud najdes cernou tecku
            if (pole[row][col] == 1){

                // prochazej zleva doprava po radku
                int posx = col+1;
                while ( posx < radek.length() and pole[row][posx] == 1){

                    // pokud muzes odbocit dolu, jdi tak dlouho dolu, dokud to jde
                    int posy = row+1;
                    while (posy < radku and pole[posy][posx] == 1){

                            // pokud byla cesta doprava stejne dlouha jako je cesta dolu
                            if ( (posx-col) == (posy-row) ){
                                // zkontroluj, ze to je skutecne ctverec - tzn. ma i ostatni strany
                                bool jeCtverec = true;
                                for (int i = col; i < posx; i++){ // zkontroluj spodni horizontalni stranu
                                    if (pole[posy][i] != 1){
                                        jeCtverec = false;
                                        break;
                                    }
                                }
                                for (int i = row; i < posy; i++){ // zkontroluj levou vertikalni stranu
                                    if (pole[i][col] != 1){
                                        jeCtverec = false;
                                        break;
                                    }
                                }
                                if (jeCtverec) pocetCtvercu++;
                            }

                            posy++;
                    }

                    posx++;
                }
            }
        }
    }

    cout << pocetCtvercu << endl;

    /// vykresli ctverec
    initwindow(radku*10, radek.length()*10);
    for (int row = 0; row < radku*10; row+=10){
        for (int col = 0; col < radek.length()*10; col+=10){
            if (pole[row/10][col/10] == 0){
                rectangle(col, row, col+9, row+9);
                floodfill(col+1, row+1, WHITE);
            }
        }
    }
    getch();

    return 0;
}
