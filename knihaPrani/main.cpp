#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string vstup;
    cin>>vstup;
    string zakaz[500];
    int i=0;
    string a;
    a="asdfdf";
    int pocetZakazu=0;

    while(a!="0")
    {
        cin>>a;
        if(a!="0")
        {
            zakaz[i]=a;
            pocetZakazu++;
        }
        i++;
    }

    i=0;
    int muzuMazatPocitadlo=0;
    while(i<pocetZakazu)
    {
        int pozice=vstup.find(zakaz[i]);
        if(pozice>=0)
        {
            muzuMazatPocitadlo=vstup.find(zakaz[i])+zakaz[i].length();

            for(int x=i; x++; x<pocetZakazu)
            {int pozice=vstup.find(zakaz[x]);
            if(pozice>=0 and muzuMazatPocitadlo>zakaz[x].length()+pozice){muzuMazatPocitadlo=pozice+zakaz[x].length(); i=x;}}

            vstup.erase(vstup.find(zakaz[i]),zakaz[i].length());

            i=0;
        }
        else i++;
    }

    cout << vstup << endl;
    return 0;
}
