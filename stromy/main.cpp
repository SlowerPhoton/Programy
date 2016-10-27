#include <iostream>
#include <fstream>

using namespace std;

//nedodelano pro zbytek je 0, problem byl v prevodu z desetinnych cisel na int

int main()
{   ifstream vstup;
    vstup.open("zadani.in");

    ofstream vystup;
    vystup.open("vysledek.txt");

    int pocetStromu=0;
    vstup>>pocetStromu; cout<<pocetStromu<<endl;

    int druh;
    vstup>>druh; cout<<druh<<endl;

    int kolik;
    vstup>>kolik; cout<<kolik<<endl;

    int pole[pocetStromu+1];
    int celkemVPoli=0;

    int odpocet = 0;
    while(odpocet<pocetStromu){
        int neco;
        vstup >> neco;

        if (neco==druh){
            pole[celkemVPoli]=odpocet;
            celkemVPoli++;
            }

        odpocet++;
    }
    odpocet--;
    cout<<celkemVPoli<<endl;

    int zbytek = kolik%celkemVPoli; cout<<"zb "<<zbytek<<endl;
    if(zbytek!=0){
        cout<<kolik/celkemVPoli<<endl;
        long long int poradi= 0;
        cout<<kolik/celkemVPoli*pocetStromu<<endl;
        poradi =kolik/celkemVPoli;
        poradi*=pocetStromu; cout<<poradi<<endl;

        poradi+=pole[zbytek-1]+1;


        vystup<<poradi;}
    else{
        long long int poradi=(kolik/celkemVPoli-1)*pocetStromu; cout<<poradi;
        poradi+=pole[celkemVPoli-1];
        poradi++;

        vystup<<poradi;}

    vstup.close();
    vystup.close();

    return 0;
}
