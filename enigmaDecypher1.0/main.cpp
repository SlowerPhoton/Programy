#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <string>

#define SIZE 26
#define SCRAMBLERS 3
using namespace std;

int main()
{
    char openText[256];
    cin >> openText;

    // fill the scrambler from a file enigma.txt (Desktop)
    int scramblers[SCRAMBLERS][SIZE];
    fstream cypher;
    cypher.open("C:\\Users\\HP\\Desktop\\slehh.txt");
    for(int j = 0; j < SCRAMBLERS; j++){
        for(int i = 0; i < SIZE; i++){
            cypher >> scramblers[j][i];
        }
    }
    cypher.close();


    int shift[SCRAMBLERS] = {0,0,0};
    char c;
    int a;
    for(int i = 0, n = strlen(openText); i < n; i++){

        // preved sifrovany text do tiskacich
        c = openText[i];
        c = toupper(c);

        // pokud je sifrovany znak pismeno, jinak ho nech nezmeneny
        if(c >= 'A' and c <= 'Z'){

            // desifruj skrze vsechny scramblers
            for(int j = SCRAMBLERS - 1; j >= 0; j--){

                // najdi c ve scramblers
                a = 0;
                while(scramblers[j][a] != c - 'A'){
                    a++;
                }

                // (semi)desifruj c
                if(a + shift[j] >= 26){
                    c = a + shift[j] + 'A' - 26;
                }
                else
                    c = a + shift[j] + 'A';

            }

            // zvys shift
            shift[1]++;
            if(shift[1] == 26){
                shift[2]++;
                shift[1] = 0;

                if(shift[2] == 26){
                    shift[3]++;
                    shift[2] = 0;

                    if(shift[3] == 26){
                        shift[3] = 0;
                    }
                }

            }
        }

        // vypis desifrovany znak
        cout << c;

    }

    return 0;
}
