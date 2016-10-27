#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <string>

#define SIZE 26
using namespace std;

int main()
{
    char openText[256];
    cin >> openText;

    // fill the scrambler from a file enigma.txt (Desktop)
    int scramblers[SIZE];
    ifstream cypher;
    cypher.open("C:\\Users\\HP\\Desktop\\happyNewYear.txt");
    int i = 0;
    while(cypher >> scramblers[i]){
        i++;
    }
    cypher.close();

    int shift = 0;
    char c;
    int a;
    for(int i = 0, n = strlen(openText); i < n; i++){

        // preved sifrovany text do tiskacich
        c = openText[i];
        c = toupper(c);

        // pokud je sifrovany znak pismeno, jinak ho nech nezmeneny
        if(c >= 'A' and c <= 'Z'){

            // kam se ve scrambles podivat
            a = 0;
            while(scramblers[a] + 'A' != c){
                a++;
            }

            if(a - shift < 0){
                c = scramblers[a - shift + 26] + 'A';
            }
            else
                c = scramblers[a - shift] + 'A';

            // zvys shift
            shift++;
            if(shift==26){
                shift = 0;
            }
        }

        // vypis desifrovany znak
        cout << c;


    }

    return 0;
}
