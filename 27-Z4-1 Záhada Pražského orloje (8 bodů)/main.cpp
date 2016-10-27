#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{   ifstream mujSoubor;
    mujSoubor.open("zadani.in");
    ofstream vysledek;
    vysledek.open("vysledek.in");
    unsigned long N;
    mujSoubor>>N;
    unsigned long n=N;
    //long int poleOdpovedi[5001];

    while(N!=0)
    {
        unsigned long A,B;
        mujSoubor>>A;
        mujSoubor>>B;
        unsigned long a=2,b=2;
        //bool prvni=true;
        unsigned long pocetOtocek=1;
        if(A%B==0){pocetOtocek=A/B;}
        else{if(B/A==0){pocetOtocek=B/A;}
        else
        while(a!=1 or b!=1)
        {
            if(a<A)
            {
                a++;
            }
            else
            {
                a=1;
            }
            if(b<B)
            {
                b++;
            }
            else
            {
                b=1;
            }
            pocetOtocek++;
            /*cout<<"a = "<<a<<endl;
            cout<<"b = "<<b<<endl;*/
        }}
        N--;
        //poleOdpovedi[N]=pocetOtocek;
        vysledek<<pocetOtocek<<endl;
        cout<<"done "<<N<<endl;
        cout<<pocetOtocek<<endl;
    }
   /* for(n; n>0; n--)
        vysledek<<poleOdpovedi[n-1]<<endl;*/
        mujSoubor.close();
        vysledek.close();
    return 0;
}
