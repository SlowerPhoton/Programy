#include <iostream>

using namespace std;

class clovek{string jm;
             int vek;
             public:
             clovek(string pjm, int pvek);
             void tisk();
             ~clovek(){cout<<"destruktor clovek"<<endl;}
};

class ridic:public clovek{string rp;
             public:
             ridic(string pjm, int pvek, string prp);
             void tisk();
             ~ridic(){cout<<"destruktor ridic"<<endl;}
};

clovek::clovek(string pjm, int pvek){

cout<<"konstruktor clovek"<<endl;
jm=pjm; vek=pvek;
}
void clovek::tisk(){
cout<<jm<<" "<<vek<<" ";
}

ridic::ridic(string pjm, int pvek, string prp):clovek(pjm, pvek),rp(prp)
{
cout<<"conctructor ridic"<<endl;

}
void ridic::tisk(){
clovek::tisk();
cout<<rp;
}


int main()
{
    ridic *Pepa;
    Pepa=new ridic("Pepa",30,"45642313");
    Pepa->tisk();
    delete(Pepa);
    return 0;
}
