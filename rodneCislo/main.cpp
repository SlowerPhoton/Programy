#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
class RodneCislo{public:
             string rc;

             RodneCislo(string prc){rc=prc;}
             virtual void Vypis(){cout<<"rc: "<<rc<<endl;}
             void Datum(){//kdyz mesicNarozeni>12, mesicNarozeni-=50;
                 cout<<rc.substr(4,2)<<"."<<rc.substr(2,2)<<".19"<<rc.substr(0,2)<<endl;}
             void ZM(){//kdyz mesic>12 => zena, substract zena.mesicNarozeni by 50
                 cout<<"muz"<<endl; cout<<"zena"<<endl;}
};

class Osoba:public RodneCislo{
    public:
    string jmeno;
    Osoba(string prc, string pjmeno);
    virtual void Vypis(){cout<<"rc: "<<rc<<" jmeno: "<<jmeno<<endl;}

};
Osoba::Osoba(string prc, string pjmeno):RodneCislo(prc){
    jmeno=pjmeno;
}

int main()
{
    RodneCislo *neco;
    Osoba *necoo;
    necoo=new Osoba("8853262176","pavla");
    neco=new RodneCislo("1505190016");
    neco->Vypis();
    neco->Datum();
    cout<<necoo->jmeno<<endl;
    cout<<necoo->rc<<endl;
    necoo->Vypis();
    delete neco; delete necoo;



    return 0;
}
