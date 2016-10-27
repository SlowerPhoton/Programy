#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct zavorka{
    int pozice;
    zavorka *dalsi;
    int druh;
    int velikostMezery;
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

int main()
{
    ifstream vstup;
    vstup.open("zadani2.in");

    ofstream vystup;
    vystup.open("vysledek.txt");

    string zavorky;

    int pocetKol;
    vstup>>pocetKol;

    while(pocetKol>0){
        zacatek = NULL;
        poziceg=0;
        vstup>>zavorky;
        for(int i=0; i<zavorky.size(); i++){
            if(zavorky[i]=='('){
            pridejZavorku(0);
            }
            if(zavorky[i]==')'){
            pridejZavorku(1);
            }
        }
        pocetKol--;





     /*while(i<13){
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
    cout<<endl;*/

    zavorka *pom;
    /*pom=zacatek;
    while(pom!=NULL){
        cout<< pom->pozice<<": "<<pom->druh<<endl;
        pom=pom->dalsi;
    }
    cout<<endl;*/

    pom = zacatek;
    bool zmena = true;
    while(zmena){
            zmena = false;
            pom=zacatek;
        while(/*pom!=NULL and */pom->dalsi!=NULL){
            /*cout<<"resime polohu "<<pom->pozice<<endl;
            zavorka *uk;
            uk=zacatek;
            while(uk!=NULL){
                cout<< uk->pozice<<": "<<uk->druh<<endl;
                uk=uk->dalsi;
            }
            cout<<endl;*/
            if(pom->druh==1 and pom->dalsi->druh==0){
                pom->dalsi=pom->dalsi->dalsi;
                pom->druh=3;
                zmena=true;
                }
            if(pom->dalsi!=NULL)
                if(pom->dalsi->druh==3){
                    if(pom->dalsi->dalsi==NULL) pom->dalsi=NULL;
                    else pom->dalsi=pom->dalsi->dalsi;
                    zmena=true;
                }
            if(zacatek==pom and pom->druh==3){zacatek=pom->dalsi; if(zacatek==NULL)break;}

            //else{cout<<"a je to tady "<<pom->}
            //cout<<pom->pozice<<" "<<pom->druh<<endl;
            if(pom->dalsi!=NULL)pom=pom->dalsi;
        } if(zacatek==NULL)break;
    }


    if(zacatek!=NULL){
    //cout<<endl;

        pom=zacatek;
        //int velikostMezery=poziceg-1-pom->pozice;
        /*if(pom->dalsi!=NULL)pom=pom->dalsi;
        while(pom!=NULL){ cout<<velikostMezery<<endl;
            if(pom->dalsi!=NULL){
                if(velikostMezery<(pom->pozice-pom->dalsi->pozice-1)) velikostMezery=(pom->pozice-pom->dalsi->pozice-1);
            }
            else {if(velikostMezery<pom->pozice)velikostMezery=pom->pozice;}
            if(pom->dalsi!=NULL)pom=pom->dalsi;
            else break;
        }
        if(velikostMezery<pom->pozice)velikostMezery=pom->pozice;*/
        while(pom->dalsi!=NULL){
            //if(velikostMezery<(pom->pozice-pom->dalsi->pozice-1)) velikostMezery=(pom->pozice-pom->dalsi->pozice-1);
            pom=pom->dalsi;
        }
        //if(velikostMezery<pom->pozice)velikostMezery=pom->pozice;
        vystup<<pom->pozice<<endl;
    }
    else vystup<<poziceg<<endl;
    }

    vstup.close();
    vystup.close();
    return 0;
}
