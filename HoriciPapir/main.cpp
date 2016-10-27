#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>



using namespace std;

int vzdalenost(int x1, int y1, int x2, int y2){

    if(x1 == x2){
        return abs(y1-y2);
    }

    if(y1 == y2){
        return abs(x1-x2);
    }

    int answer = 0;

    int a1, a2;
    a1 = abs(x1-x2);
    a2 = abs(y1-y2);

    int a;
    if (a1 < a2) {
        a = a1;

        if(x1 < x2)
            x1 += a;
        else
            x1 -= a;

        if(y1 < y2)
            y1 += a;
        else
            y1 -= a;


    }
    else {
        a = a2;

        if(y1 < y2)
            y1 += a;
        else
            y1 -= a;

        if(x1 < x2)
            x1 += a;
        else
            x1 -= a;
    }

    if(x1 == x2){
        return abs(y1-y2) + a;
    }

    if(y1 == y2){
        return abs(x1-x2) + a;
    }

    else{
        cout << "shit" << endl;
    }


}
int main()
{
    ifstream vstup;
    vstup.open("vstup.txt");

    ofstream output;
    output.open("output.txt");

    int pocetVstupu;
    vstup >> pocetVstupu;

    for(int cykl = 0; cykl < pocetVstupu; cykl++){
        cout << cykl << "/" << pocetVstupu-1 << endl;

        int rad, sl;
        vstup >> rad; vstup >> sl;

        int ohnu;
        vstup >> ohnu;

        int *ohne;
        ohne = new int[ohnu*2];

        for(int i = 0; i < ohnu; i++){

            vstup >> ohne[i*2];
            vstup >> ohne[i*2+1];

        }

        int vz = 0;
        for(int r = 0; r < rad; r++){

            for(int s = 0; s < sl; s++){
                int m = INT_MAX;
                for(int k = 0; k < ohnu; k++){
                    int mezi = vzdalenost(r, s, ohne[k*2], ohne[k*2+1]);
                    //cout << "mezi: " << mezi << endl;
                    //if (mezi == 4) cout << "4! r = " << r <<" s = " << s << " : " << ohne[k*2] << ", " << ohne[k*2+1] << endl;
                    if(mezi < m) m = mezi;
                    if (mezi < vz) break;
                }
                if(m > vz) vz = m;
            }
        }

        output << vz << endl;
        delete[] ohne;

    }




    vstup.close();
    output.close();

    return 0;
}
