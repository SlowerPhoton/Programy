#include <iostream>

using namespace std;

class BOD{
             int x;
             int y;
             public:
             //BOD(int px,int py);
             void tisk(){cout<<x<<" "<<y;}
};

/*BOD::BOD(int px,int py){
x=px;
y=py;
}*/

class KRUH:public BOD{
             public:
             int r;
             public:
             //ridic(string pjm, int pvek, string prp);
             KRUH(/*int px, int py, */int pr);
             void Nastavr(int pr){r=pr;}
             virtual float Obsah(){return r*r*3.14;}
             float Obvod(){return 2*r*3.14;}
             void tiskKruh(){cout<</*x<<" "<<y<<" "<<*/r;}
             //~ridic(){cout<<"destruktor ridic"<<endl;}
};

KRUH::KRUH(/*int px, int py, */int pr)//:/*BOD(px, py),*/ r(pr)
{   r=pr;
    //cout<<"konstructor KRUH"<<endl;
}

class VALEC:public KRUH{
            public:
            int v;
            VALEC(/*int px, int py,*/ int pr, int pv);
            void Nastavv(int pv){v=pv;}
            virtual float Obsah(){return 2*r*v*3.14;}
            float Objem(){/*cout<<"obvod "<<Obvod()<<endl;*/return r*r*v*3.14;}

            void tiskValec(){cout/*<<x<<" "<<y<<" "*/<<r<<" "<<v<<endl;}

};

VALEC::VALEC(/*int px, int py,*/ int pr, int pv):KRUH(/*px, py,*/ pr), v(pv)
{
    //cout<<"konstructor VALEC"<<endl;
}



/*VALEC::Obsah(){
return r*r*3.14*v;

}*/


int main()
{

    /*KRUH *kruh;
    kruh = new KRUH(3);
    kruh->tiskKruh();
    VALEC *valec;
    valec = new VALEC(3,4);
    valec->tiskValec();
    cout<<kruh->Obsah()<<endl;
    kruh->Nastavr(1);
    kruh->Obsah();
    cout<<valec->Obsah()<<endl;
    cout<<valec->Objem()<<endl;*/

   KRUH *MUJKRUH;         VALEC   *MUJVALEC ;
	MUJKRUH = new KRUH(1);MUJKRUH->Nastavr(1);
	MUJVALEC = new VALEC(3,1);MUJVALEC->Nastavv (1);
cout << "KRUH obsah a obvod"<<MUJKRUH->Obsah()<< "\t"<<MUJKRUH->Obvod();
cout << "VALEC obsah a obvod"<<MUJVALEC->Obsah()<< "\t"<<MUJVALEC->Objem();
	delete MUJKRUH;
	delete MUJVALEC;

return 0;

}

