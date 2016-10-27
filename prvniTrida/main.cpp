#include <iostream>
#include <fstream>

using namespace std;

int tridaG = 1;

struct prvnak{
    int jmeno;
    int trida;
    prvnak *dalsi;
};

prvnak *zacatek;

void pridejPrvnaka(int jmeno, int trida){
    prvnak *pom;
    pom = new prvnak;
    pom->trida=trida;
    pom->jmeno=jmeno;
    pom->dalsi=zacatek;
    zacatek=pom;
    //cout<<"pridavam "<<jmeno<<" do tridy "<<trida<<endl;
}

int main()
{   zacatek=NULL;

    ifstream vstup;
    vstup.open("zadani.in");

    ofstream vystup;
    vystup.open("vysledek.txt");

    int pocetKol, pocetDeti;
    vstup>>pocetDeti;
    vstup>>pocetKol; //cout<<pocetKol<<endl;

    int jmeno; vstup>>jmeno;
    pridejPrvnaka(jmeno, tridaG);
    vstup>>jmeno;
    pridejPrvnaka(jmeno, tridaG);
    pocetKol--;

    //nacteni
    while(pocetKol>0){
        int duplikace=0;
        prvnak *pom;
        pom=zacatek;
        int jmeno1, jmeno2;
        vstup>>jmeno1; vstup>>jmeno2;

        while(pom->dalsi!=NULL){
            if(jmeno1==pom->jmeno or jmeno2==pom->jmeno){duplikace=pom->trida; break;}
            pom=pom->dalsi;
        }

        if(duplikace==0){tridaG++; pridejPrvnaka(jmeno1, tridaG); pridejPrvnaka(jmeno2, tridaG);}
        else {pridejPrvnaka(jmeno1, duplikace); pridejPrvnaka(jmeno2, duplikace);}


        //cout<<pocetKol<<endl;
        pocetKol--;
    }

    //core
    prvnak *stator; prvnak *rotor;
    stator = zacatek;
    while(stator!=NULL){
        rotor=stator->dalsi;
        while(rotor!=NULL){
            if(stator->jmeno==rotor->jmeno){
                int presouvame=rotor->trida;
                //cout<<"rovnaji se stator a rotor jmena "<<rotor->jmeno<<endl;
                prvnak *pom;
                pom=zacatek;
                while(pom!=NULL){
                    if(pom->trida==presouvame){
                        //cout<<"rovnaji se pom a rotor tridy "<<rotor->trida<<endl;
                        pom->trida=stator->trida;
                    }
                    pom=pom->dalsi;
                }
            }
            rotor=rotor->dalsi;
        }
        stator=stator->dalsi;
    }

    //vypis, nic vic
    prvnak *pom;
    pom=zacatek;
    int pole[1000];
    pole[0]=0;
    int i;
    int pocet=0;

    while(pom!=NULL){
        //cout<<pom->jmeno<<" "<<pom->trida<<endl;

        i=0;
        bool duplikat = false;
        while(pole[i]!=0){
            if(pole[i]==pom->trida){duplikat=true; break;}
            i++;
        }
        if(duplikat==false){
            pole[i]=pom->trida;
            pole[i+1]=0;
            pocet++;
        }

        pom=pom->dalsi;
    }

    //deti, co chybely
    for(i=1; i<pocetDeti+1; i++){
        bool neni=true;
        pom=zacatek;
        while(pom!=NULL){
            if(i==pom->jmeno){neni=false; break;}
            pom=pom->dalsi;
        }
        if(neni){pocet++;}
    }

    vystup<<pocet;

    vstup.close();
    vystup.close();

    return 0;
}
