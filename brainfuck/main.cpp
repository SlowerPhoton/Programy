#include <iostream>

using namespace std;

int main()
{ int cislo=0;
    char p[40];
    int posofcomp;
    cin>>p;

for(int i=0; i<40; i++){
    if(p[i]=='<' or p[i]=='>'){
        posofcomp=i; i=600;}}

for(int i=0; i<posofcomp; i++){
    if(p[i]=='+')cislo++;
    if(p[i]=='-')cislo--;
}

for(int i=posofcomp; i<20; i++){
    if(p[posofcomp+1]!='<'){
    if(p[i]=='+')cislo++;
    if(p[i]=='-')cislo--;}
}

    cout << cislo << endl;
    return 0;
}
