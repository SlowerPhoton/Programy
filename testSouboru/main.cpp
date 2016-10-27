#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{   int radky=1, sloupce=2;
    //cin>>radky>>sloupce;
    char vstup='a';
    ifstream zadani;
    zadani.open("zadani5.in");
    zadani>>sloupce;
    zadani>>radky;



    bool okna[radky][sloupce];
    string a="asdgasdgasdga";
    string b="bsbsbsbsb";
    for(int radek=0;radek<radky;radek++){
            zadani>>a;
    for(int i=0; i<sloupce;i++){
        if(a[i]=='.'){okna[radek][i]=0;}
        else okna[radek][i]=1;
    }}

    for(int radek=0;radek<radky;radek++){
    for(int i=0; i<sloupce;i++)
    cout<<okna[radek][i]<<" ";
    cout<<endl;
    }
    //std::string s;
    //std::cout << "Maximum size of a string is " << s.max_size() << "\n";

   // zadani>>sloupce;
    //zadani.get(vstup);
    //cout<<"vstup "<<vstup<<endl;
    //cout<<radky<<" "<<sloupce<<endl;

    /*for(int i=0; i<radky; i++){
        //cout<<"radek: "<<i+1<<endl;
        for(int y=0; y<sloupce; y++){
            zadani.get(vstup);
            if(vstup=='.' or vstup=='0')okna[i][y]=0;
            if(vstup=='#') okna[i][y]=1;
        }
        cout<<vstup<<endl;
    }
    for(int i=0; i<radky; i++){
        for(int y=0; y<sloupce; y++){
            cout<<okna[i][y];
            }
        cout<<endl;
    }*/

    return 0;
}
