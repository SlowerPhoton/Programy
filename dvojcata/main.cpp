#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int maxLength = 0;
    char y = '\n';

    ifstream inp;
    inp.open("2G.txt");

    string retezec;
    inp >> retezec;
    if (retezec.length() < 1)
        return 1;
    char x;
    size_t pos = 0;
    while (pos < ( retezec.length() - 1 ) /* pos < 3*/){

        x = retezec[pos];
        int k = 0;
        int length = 0;
        while ( ( pos+1+k ) < retezec.length()){ // vyzkousej vsechny mozne nalezitelne retezce x2
            length = 0;
            int pos2 = retezec.find(x, pos+1+k);
            if (pos2 == -1){
                break;
            }

            int a = pos;
            int b = pos2;
            while ( b < retezec.length() and retezec[a] == retezec[b] ){
                if (a+1 == pos2){
                    length = 0;
                    break;
                }
                if (a >= pos2) {
                    break;
                }
                a++;
                b++;
                length++;
            }
            if (length > maxLength){
                maxLength = length;
                y = retezec[a];
            }
            k++;
        }
        pos++; // hledej zase dal
    }
    // pokud retezec x je prazdny, y je na prvni pozici retezce
    if (y == '\n')
        y = retezec[0];

    cout << y;

    inp.close();

    return 0;
}
