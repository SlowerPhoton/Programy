#include <iostream>

using namespace std;
struct zavorka{
    int pozice;
    zavorka *dalsi;
    //zavorka *predchozi;
    int druh;
};
int poziceg=0;

zavorka *zacatek;

void pridejZavorku(bool druh){
    zavorka *pom;
    pom = new zavorka;
    pom->pozice=poziceg; poziceg++;
    if(druh==0){pom->druh=0;}
    else pom->druh=1;
    pom->dalsi=zacatek;
    zacatek=pom;
    //cout<<"pridavam "<<poziceg<<endl;
}

void odeberZavorku(){
    zacatek = zacatek->dalsi;
    //poziceg--;
    cout<<"odebiram "<<poziceg<<endl;
}

int main()
{   zacatek = NULL;
    char zavorky [13] = {'(','(',')','(',')',')','(','(','(',')','(',')',')'};
    int i=0;
    char znak;

    //pocatecni yachranna zavorka
    zavorka *pom;
    pom = new zavorka;
    pom->pozice=-1;
    pom->druh=3;
    pom->dalsi=NULL;
    zacatek=pom;

    //nasledujici cast se bude menit na nacet ye souboru
    while(i<13){
        znak = zavorky[i]; i++;
        cout<<znak;
        if(znak=='('){
            pridejZavorku(0);
            //cout<<"i je "<<i<<" a pridavam "<<endl;
           }
        if(znak==')'){
            pridejZavorku(1);
            //cout<<"i je "<<i<<" a odebiram"<<endl;
        }
    }
    cout<<endl;

    //nemenit / proc pada
    pom = zacatek;
    bool zmena = true;
    while(zmena){
            zmena = false;
            pom=zacatek;
        while(/*pom!=NULL and */pom->dalsi!=NULL){
            if(pom->dalsi->druh==3){
                pom->dalsi=pom->dalsi->dalsi;
                zmena=true;
            }
            if(pom->dalsi!=NULL)
            if(pom->druh==1 and pom->dalsi->druh==0){
                cout<<"nalezen match pro pozice "<<pom->pozice<<" a "<<pom->dalsi->pozice<<endl;
                pom->dalsi=pom->dalsi->dalsi;
                pom->druh=3;
                zmena=true;
                }
            //cout<<pom->pozice<<" "<<pom->druh<<endl;
            pom=pom->dalsi;
        }
    }
    cout<<endl;

    //vypis posleze zmenit
    pom=zacatek;
    while(pom!=NULL){
        cout<< pom->pozice<<": "<<pom->druh<<endl;
        pom=pom->dalsi;
    }

    return 0;
}
