#include <iostream>
#include <fstream>

using namespace std;

int main()
{   ifstream vstup;
    vstup.open("zadani.in");

    ofstream vystup;
    vystup.open("vysledek.txt");

    int pocetKol;
    vstup>>pocetKol;

    while(pocetKol>0){
    int N; vstup>>N;
    int M; vstup>>M;

    /*cout<<N<<" ";
    cout<<M<<endl;*/

    bool zakrouzkovano=0;
    for(int i=2; i<M; i++){
        if(N%i==0){
            if(zakrouzkovano==0)zakrouzkovano=1;
            else zakrouzkovano=0;
        }
    }

    if(zakrouzkovano==0)vystup<<"NE"<<endl;
    else vystup<<"ANO"<<endl;

    pocetKol--;
    }

    vstup.close();
    vystup.close();

    return 0;
}
