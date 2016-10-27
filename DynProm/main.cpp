#include <iostream>

using namespace std;


struct TPRVEK{
int cislo;
TPRVEK *dalsi;
};

TPRVEK *zacatek;

void pridejNaZacatek(int hodnota){
 TPRVEK *pom;
 pom = new TPRVEK;
 pom->cislo = hodnota;
 pom->dalsi = zacatek;
 zacatek = pom;
}


int main()
{   //TPRVEK *zacatek;
    //zacatek = new TPRVEK;
    zacatek = NULL;
    //cout<<zacatek->cislo;*/

    /*TPRVEK *nutne;
    nutne = new TPRVEK;
    nutne->dalsi=NULL;
    nutne->cislo=1;*/

    pridejNaZacatek(4);
    pridejNaZacatek(3);
    pridejNaZacatek(2);
    pridejNaZacatek(1);
    pridejNaZacatek(5);
    pridejNaZacatek(6);

    //zacatek->dalsi=nutne;

    /*TPRVEK *ukazatel;
    ukazatel=zacatek;
    for(int i=0; i<3; i++){
    cout<<ukazatel->cislo<<endl; ukazatel=ukazatel->dalsi;}*/
    TPRVEK *pom;
    pom = zacatek;
    while(pom!=NULL){
    cout << pom->cislo << endl;
    pom = pom->dalsi;
    }


    //void pridejNaZacatek(int hodnota){
/* TPRVEK *pom;
 pom = new TPRVEK;
 pom->cislo = 5;
 pom->dalsi = zacatek;
 zacatek = pom;*/
//}

    /*int *p;
    p = new int;
    *p=10;
    p[0]=2;
    p[2]=4;
    p[1]=3;
    p[100]=10;
    int *q;
    q = new int;
    cout<<p<<" "<<*p<<" "<<p[0]<<" "<<p[1]<<" "<<p[2]<<*q;
    for(int a=0; a<10; a++)
    cin>>*(q+a);
    q=NULL;
    int h;
    int *huk; huk= new int; huk=*h;


    for(int a=0; a<10; a++)cout<<q[a]<<" ";*/




    return 0;

    cout<<"hi";
}
