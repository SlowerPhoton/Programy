#include <iostream>
#include <fstream>

using namespace std;

struct Slovo{
    int cetnost;
    string slovo;
    Slovo *dalsi;
};

Slovo *zacatek;

void pridejSlovo(string nove){
    Slovo *pom;
    pom = new Slovo;
    pom->cetnost=1;
    pom->slovo = nove;
    pom->dalsi = zacatek;
    zacatek=pom;
}

void vypis(){
    Slovo *pom;
    pom = zacatek;
    while(pom!=NULL){
        cout<<pom->slovo<<" "<<pom->cetnost<<endl;
        pom=pom->dalsi;
    }
}

int main()
{
    string nacteno;
    ifstream zdroj("zdroj1.txt");
    int pocetSlov=0;

    zacatek=NULL;

    while(!zdroj.eof()){
        zdroj>>nacteno;
        Slovo *pom;
        pom = zacatek;
        while(pom!=NULL and pom->slovo!=nacteno){
            pom=pom->dalsi;
        }

        if(pom==NULL) {pridejSlovo(nacteno); pocetSlov++;}
        else pom->cetnost++;
    }

    vypis();

    cout<<pocetSlov;

    zdroj.close();

    return 0;
}
