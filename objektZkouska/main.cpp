#include <iostream>

using namespace std;
class clovek1{
    public:  string jm;
             int vek;
             public:
             clovek1(string pjm, int pvek);
             //void clovek1(){cout<<"jsem pes"<<endl;} nejede
             ~clovek1(){cout<<"jsem pes"<<endl;}
};
clovek1::clovek1(string pjm, int pvek){

cout<<"konstruktor clovek"<<endl;
jm=pjm; vek=pvek;
/*cout<<"yadej jmeno a vek";
cin>>jm>>vek;*/
}

/*void clovek1::pes(){
cout<<"jsem pes"<<endl;}*/

int main()
{
    clovek1 Anna("Anna",15);
    cout<<Anna.jm<<" "<<Anna.vek;
    //Anna.clovek1();
    //Anna.pes();
    /*clovek *Anna;
    Anna = new clovek("Anna",15);*/


    return 0;
}
