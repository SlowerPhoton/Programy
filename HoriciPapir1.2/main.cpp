#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>



using namespace std;

bool doesitcover(int sq1, int sq2, int a, int x, int y){
    return (x >= sq1 and (sq1+a)>x and y >= sq2 and (sq2+a)>y);
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
        vstup >> rad; vstup >> sl;

        if(rad == 0) cout <<"rad 0" << endl;
        if(sl == 0) cout <<"sl 0" << endl;

        int ohnu;
        vstup >> ohnu;

        int mn = INT_MAX;
        for(int i = 0; i < ohnu; i++){
            int x, y;
            vstup >> x;
            vstup >> y;

            int sq1 = x, sq2 = y, a = 1;
            int zeit = 0;
            while(true){
                // check if it doesn't cover the whole paper already
                if(doesitcover(sq1, sq2, a, 0, 0) and doesitcover(sq1, sq2, a, sl-1, 0) and doesitcover(sq1, sq2, a, 0, rad-1) and doesitcover(sq1, sq2, a, sl-1, rad-1)){
                    break;
                }

                zeit++;

                if((sq1-1) >= 0) sq1--;
                if((sq2-1) >= 0) sq2--;
                a+=2;
            }

            if(zeit < mn) mn = zeit;

        }

        output << mn << endl;

    }




    vstup.close();
    output.close();

    return 0;
}
