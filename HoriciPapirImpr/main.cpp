#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>



using namespace std;
/*
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


}*/
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

        cout << "rad " << rad << endl;
        cout << "sl " << sl << endl;

        int ohnu;
        vstup >> ohnu;

        int *pole;
        pole = new int[rad*sl];

        if(pole == NULL) cout << "polnull" << endl;

        cout << "pole vytvoreno " << endl;

        for(int i = 0, a = rad*sl; i < a; i++)
            pole[i] = 2;

        for(int i = 0; i < ohnu; i++){
            int x, y;
            vstup >> x;
            vstup >> y;

            pole[y*sl+x] = 1;

        }
        cout << "here";

        bool zmena = true;
        int zeit = 0, debug = 0;
        while(zmena){
            zmena = false;
            for(int r = 0; r < rad; r++){
                for(int s = 0; s < sl; s++){

                    if(pole[r*sl+s] == 1){
                        if((s+1) < sl   and pole[r*sl+s+1]==2){ pole[r*sl+s+1] = 1; zmena = true;} cout <<"1 ";
                        if((s-1) >= 0   and pole[r*sl+s-1]==2){ pole[r*sl+s-1] = 1; zmena = true;}cout <<"2 ";
                        if((r+1) < rad  and pole[(r+1)*sl+s]==2){ pole[(r+1)*sl+s] = 1; zmena = true;}cout <<"3 ";
                        if((r-1) >= 0   and pole[(r-1)*sl+s]==2){ pole[(r-1)*sl+s] = 1; zmena = true;}cout <<"4 ";
                        if((r+1) < rad  and (s+1) < sl              and pole[(r+1)*sl+s+1]==2){ pole[(r+1)*sl+s+1] = 1; zmena = true;}cout <<"5 ";
                        if((r+1) < rad  and (s-1) >= 0              and pole[(r+1)*sl+s-1]==2){ pole[(r+1)*sl+s-1] = 1; zmena = true;}cout <<"6 ";
                        if((r-1) >= 0   and (s+1) < sl              and pole[(r-1)*sl+s+1]==2){ pole[(r-1)*sl+s+1] = 1; zmena = true;}cout <<"7 ";
                        if((r-1) >= 0   and (s-1) >= 0              and pole[(r-1)*sl+s-1]==2){ pole[(r-1)*sl+s-1] = 1; zmena = true;}cout <<"8 ";
                        pole[r*sl+s] = 0; cout << endl;
                    }

                }
            }

            zeit++;
            debug++;
            cout << "kolo: " << debug << endl;

        }

        output << zeit << endl;

        cout << "answer: " << zeit << endl;

        cout << "pole: " << pole << endl;
        //delete[] pole;

        cout << "pole smazano " << endl;

    }




    vstup.close();
    output.close();

    return 0;
}
