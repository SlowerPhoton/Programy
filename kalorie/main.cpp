#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <graphics.h>



using namespace std;

int main()
{   initwindow(800,600);
    ifstream mujSoubor;
    mujSoubor.open("kalorie.tcx");
    string radek;
    float kalorieCelkem=0;

    while(getline(mujSoubor,radek)){
    int pozice=radek.find("<Calories>");
    int pozice2=radek.find("</Calories>");
    if(pozice!=-1){
       string kalorieText = radek.substr(pozice+10,pozice2-pozice-10);
       kalorieCelkem=kalorieCelkem+atof(kalorieText.c_str());}}
    mujSoubor.close();


    ifstream mujSoubor1;
    mujSoubor1.open("kalorie.tcx");
    float vzdalenostCelkem=0;
    bool pritomnostLap=false;
    string radek1;
    while(getline(mujSoubor1,radek1)){
    if(radek1.find("<Lap")!=-1){pritomnostLap=true;}
    if(pritomnostLap){
    int pozice=radek1.find("<DistanceMeters>");
    int pozice2=radek1.find("</DistanceMeters>");
    if(pozice!=-1){
       pritomnostLap=false;
       string vzdalenostText = radek1.substr(pozice+16,pozice2-pozice-16);
       vzdalenostCelkem=vzdalenostCelkem+atof(vzdalenostText.c_str());
       pozice=-1;}}}
    mujSoubor1.close();

    ifstream mujSoubor2;
    mujSoubor2.open("kalorie.tcx");
    float casCelkem=0;
    pritomnostLap=false;
    string radek2;
    while(getline(mujSoubor2,radek2)){
    if(radek2.find("<Lap")!=-1){pritomnostLap=true;}
    if(pritomnostLap){
    int pozice=radek2.find("<TotalTimeSeconds>");
    int pozice2=radek2.find("</TotalTimeSeconds>");
    if(pozice!=-1){

       pritomnostLap=false;
       string casText = radek2.substr(pozice+18,pozice2-pozice-18);
       casCelkem=casCelkem+atof(casText.c_str());
       pozice=-1;}}}
    mujSoubor2.close();

    fstream mujSoubor3;
    mujSoubor3.open("kalorie.tcx");
    double sirka=0;
    double delka=0;
    string radek3;
    while(getline(mujSoubor3,radek3)){
    int pozicex = radek3.find("<LatitudeDegrees>");
    int pozicey = radek3.find("</LatitudeDegrees>");

    if(pozicex!=-1){
    string sirkaText = radek3.substr(pozicex+17,pozicey-pozicex-17);
    sirka=atof(sirkaText.c_str());
   }

    pozicex = radek3.find("<LongitudeDegrees>");
    pozicey = radek3.find("</LongitudeDegrees>");

    if(pozicex!=-1){
    string delkaText = radek3.substr(pozicex+18,pozicey-pozicex-18);
    delka=atof(delkaText.c_str());



       }


    }

    mujSoubor3.close();
    ifstream mujSoubor4;
    mujSoubor4.open("kalorie.tcx");
    string radek4;
    double maxSirka=0;
    double maxDelka=0;
    double minSirka=50;
    double minDelka=50;

    while(getline(mujSoubor4,radek4)){
        int pozicex = radek4.find("<LatitudeDegrees>");
        int pozicey = radek4.find("</LatitudeDegrees>");

        if(pozicex!=-1){
    string sirkaText = radek4.substr(pozicex+17,pozicey-pozicex-17);
    double mezipocet = atof(sirkaText.c_str());
    if(mezipocet>maxSirka){maxSirka=mezipocet;}
    if(mezipocet<minSirka){minSirka=mezipocet;}}

    pozicex = radek4.find("<LongitudeDegrees>");
    pozicey = radek4.find("</LongitudeDegrees>");

    if(pozicex!=-1){
        string sirkaText = radek4.substr(pozicex+18,pozicey-pozicex-18);
        double mezipocet = atof(sirkaText.c_str());
        if(mezipocet>maxDelka){maxDelka=mezipocet;cout<<"nova maxdelka "<<mezipocet<<endl;}
        if(mezipocet<minDelka){minDelka=mezipocet;cout<<"nova mindelka "<<mezipocet<<endl;}

    }}
    mujSoubor4.close();

    //pocitani koeficientu
    double koefSirka = 300/(maxSirka-minSirka);
    double koefDelka = 300/(maxDelka-minDelka);

    //kresleni drahz
    moveto(300,300);
    fstream mujSoubor5;
    mujSoubor5.open("kalorie.tcx");
    string radek5;
    double sirl=0;
    double dell=0;
    int nacela;
    int nacela1;
    /*int sirkodelka = sirka;
    sirka=delka;
    delka = sirka;
    sirkodelka = koefSirka;
    koefSirka=koefDelka;
    koefDelka=sirkodelka;*/

     while(getline(mujSoubor5,radek5)){
        int pozicex = radek5.find("<LatitudeDegrees>");
        int pozicey = radek5.find("</LatitudeDegrees>");

        if(pozicex!=-1){
    string sirkaText = radek5.substr(pozicex+17,pozicey-pozicex-17);
    double mezipocet = atof(sirkaText.c_str());
    if(sirl==0){sirl=mezipocet;cout<<"sirl ulozena"<<endl;}
    else{
    nacela = (sirl-mezipocet)*koefSirka;

    }
    }

    pozicex = radek5.find("<LongitudeDegrees>");
    pozicey = radek5.find("</LongitudeDegrees>");

    if(pozicex!=-1){
        string sirkaText = radek5.substr(pozicex+18,pozicey-pozicex-18);
        double mezipocet = atof(sirkaText.c_str());
         if(dell==0){dell=mezipocet;cout<<"dell ulozena"<<endl;}
    else{
    nacela1 = (dell-mezipocet)*koefDelka;
    lineto(300+nacela,300+nacela1);
    delay(5);
    }

    }}
    mujSoubor5.close();


/*  cout<<kalorieCelkem<<endl;
    cout<<vzdalenostCelkem<<endl;
    cout<<casCelkem<<endl;
    cout<<vzdalenostCelkem/casCelkem*3.6<<endl;*/
     cout<<"min sirka "<< minSirka <<endl;
     cout<<"max sirka "<< maxSirka <<endl;
     cout<<"min delka "<< minDelka <<endl;
     cout<<"max delka "<< maxDelka <<endl;
     cout<<"koefSirka "<< koefSirka <<endl;
     cout<<"koefdelka "<< koefDelka <<endl;







    getch();
    return 0;
}
