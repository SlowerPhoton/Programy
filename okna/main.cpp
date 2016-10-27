#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
   int radky, sloupce;
    ifstream zadani;
    ofstream vysledek;
    vysledek.open("vysledek.txt");
    zadani.open("zadani2.in");
    //while(!zadani.eof()){
    zadani>>sloupce;
    zadani>>radky;

    cout<<radky<<" "<<sloupce;
    string vstup;
    bool okna[radky][sloupce];

    for(int i=0; i<radky; i++){
        zadani>>vstup;
        for(int y=0; y<sloupce; y++){
            if(vstup[y]=='.'/* or vstup=='0'*/)okna[i][y]=0;
            else okna[i][y]=1;
        }
    }
    /*for(int i=0; i<radky; i++){
        for(int y=0; y<sloupce; y++){
            cout<<okna[i][y];
        }
        cout<<endl;
    }*/

    /*int rozsviceno=0;
    int rozsvicenoZ;*/
    int mezivypocty[12000][40];
    int neprepisujRadky=0;
    int polohaL;
    int neprepisujRadkyZ;
    bool shodaU=false;
    bool shodaL=false;
    int neprepisujPouzit=0;
    int muzesPouzit[500];

    for(int i=0; i<radky; i++){//cout<<"i je "<<i<<endl;
        for(int y=0; y<sloupce; y++){//cout<<"y je "<<y<<endl;
            if(okna[i][y]==1){
                neprepisujRadkyZ=neprepisujRadky;

                /*for(int a=0; a<neprepisujRadky; a++){
                        cout<<"a je "<<a<<endl;
                        for(int b=mezivypocty[a][0]; b>0; b--){
                            cout<<"b je "<<b<<endl;
                            if(mezivypocty[a][b*2]==y and mezivypocty[a][b*2-1]==i){
                            shodaM=true; cout<<"shodaM"<<endl; neprepisujRadky=a; neprepisujBody=b*2+1;}
                            if(i>0){if(mezivypocty[a][b*2]==y and mezivypocty[a][b*2-1]==i-1){
                            shodaU=true;cout<<"shodaU"<<endl;  neprepisujRadky=a; neprepisujBody=b*2+1;}}
                            if(y>0){if(mezivypocty[a][b*2]==y-1 and mezivypocty[a][b*2-1]==i){
                            shodaL=true;cout<<"shodaL"<<endl;  neprepisujRadky=a; neprepisujBody=b*2+1;}}
                            if(y<sloupce-1){if(mezivypocty[a][b*2]==y+1 and mezivypocty[a][b*2-1]==i){
                            shodaR=true;cout<<"shodaR"<<endl;  neprepisujRadky=a; neprepisujBody=b*2+1;}}
                            if(i<radky-1){if(mezivypocty[a][b*2]==y and mezivypocty[a][b*2-1]==i+1){
                            shodaD=true;cout<<"shodaD"<<endl;  neprepisujRadky=a; neprepisujBody=b*2+1;}}
                            }}*/

                       /* rozsvicenoZ=mezivypocty[neprepisujRadky][0]; cout<<"rozsvicenoZ "<<rozsvicenoZ<<endl;
                        cout<<"neprepisujRadky "<<neprepisujRadky<<endl<<" neprepisujRaddkyZ "<<neprepisujRadkyZ<<endl;
                        for(int h=0;h<neprepisujRadkyZ;h++){
                            cout<<"radek "<<h<<" ";
                            cout<<mezivypocty[h][0]<<endl;}

                cout<<endl;

                if(shodaM==false){mezivypocty[neprepisujRadky][neprepisujBody]=i; mezivypocty[neprepisujRadky][neprepisujBody+1]=y; neprepisujBody+=2; rozsviceno++;}
                if(i>0 and shodaU==false){if(okna[i-1][y]==1){rozsviceno++; mezivypocty[neprepisujRadky][neprepisujBody]=i-1; mezivypocty[neprepisujRadky][neprepisujBody+1]=y  ; neprepisujBody+=2;}}
                if(y>0 and shodaL==false){if(okna[i][y-1]==1){rozsviceno++; mezivypocty[neprepisujRadky][neprepisujBody]=i  ; mezivypocty[neprepisujRadky][neprepisujBody+1]=y-1; neprepisujBody+=2;}}
                if(y<sloupce-1 and shodaR==false){if(okna[i][y+1]==1){rozsviceno++; mezivypocty[neprepisujRadky][neprepisujBody]=i  ; mezivypocty[neprepisujRadky][neprepisujBody+1]=y+1; neprepisujBody+=2;}}
                if(i<radky-1 and shodaD==false){if(okna[i+1][y]==1){rozsviceno++; mezivypocty[neprepisujRadky][neprepisujBody]=i+1; mezivypocty[neprepisujRadky][neprepisujBody+1]=y  ; neprepisujBody+=2;}}
                cout<<"roysviceno "<<rozsviceno<<" roysvicenoZ "<<rozsvicenoZ<<endl;
                if(shodaD or shodaL or shodaM or shodaR or shodaU){rozsviceno+=rozsvicenoZ;rozsvicenoZ=0;neprepisujRadkyZ--;}
                mezivypocty[neprepisujRadky][0]=rozsviceno; rozsviceno=0;
                neprepisujRadky=neprepisujRadkyZ;
                neprepisujRadky++;
                neprepisujBody=1;
                shodaD=false; shodaL=false; shodaM=false; shodaR=false; shodaU=false;*/

                for(int a=0; a<neprepisujRadkyZ; a++){
                        //cout<<"\t a je "<<a<<endl;
                        //cout<<"neprepisujRadky "<<neprepisujRadky<<endl;
                for(int b=mezivypocty[a][0]; b>0; b--){
                        //cout<<"b je "<<b<<endl;
                    if(i>0){if(mezivypocty[a][b*2]==y and mezivypocty[a][b*2-1]==i-1){
                            shodaU=true;/*cout<<"shodaU"<<endl;*/  neprepisujRadky=a; }}
                    if(y>0){if(mezivypocty[a][b*2]==y-1 and mezivypocty[a][b*2-1]==i){
                            shodaL=true;/*cout<<"shodaL"<<endl;*/  if(shodaU==false){neprepisujRadky=a;} polohaL=a;}}
                }
                }
                if(shodaU and shodaL==false){
                    mezivypocty[neprepisujRadky][mezivypocty[neprepisujRadky][0]*2+1]=i;
                    mezivypocty[neprepisujRadky][mezivypocty[neprepisujRadky][0]*2+2]=y;
                    mezivypocty[neprepisujRadky][0]++;
                }
                if(shodaL and shodaU==false){
                    mezivypocty[neprepisujRadky][mezivypocty[neprepisujRadky][0]*2+1]=i;
                    mezivypocty[neprepisujRadky][mezivypocty[neprepisujRadky][0]*2+2]=y;
                    mezivypocty[neprepisujRadky][0]++;
                }
                if(shodaL and shodaU){
                    mezivypocty[neprepisujRadky][mezivypocty[neprepisujRadky][0]*2+1]=i;
                    mezivypocty[neprepisujRadky][mezivypocty[neprepisujRadky][0]*2+2]=y;
                    mezivypocty[neprepisujRadky][0]++;
                    if(polohaL!=neprepisujRadky){for(int h=1;h<mezivypocty[polohaL][0]*2;h+=2){
                        mezivypocty[neprepisujRadky][mezivypocty[neprepisujRadky][0]*2+1]=mezivypocty[polohaL][h];
                        mezivypocty[neprepisujRadky][mezivypocty[neprepisujRadky][0]*2+2]=mezivypocty[polohaL][h+1];
                        mezivypocty[neprepisujRadky][0]++;
                    }
                    mezivypocty[polohaL][0]=0; muzesPouzit[neprepisujPouzit]=polohaL; neprepisujPouzit++;}
                }
                if(shodaL==false and shodaU==false){
                    if(neprepisujPouzit>0){
                        mezivypocty[muzesPouzit[neprepisujPouzit]][1]=i;
                        mezivypocty[muzesPouzit[neprepisujPouzit]][2]=y;
                        mezivypocty[muzesPouzit[neprepisujPouzit]][0]=1;
                        neprepisujPouzit--;
                        }
                    else{
                        mezivypocty[neprepisujRadky][1]=i;
                        mezivypocty[neprepisujRadky][2]=y;
                        mezivypocty[neprepisujRadky][0]=1;
                        neprepisujRadkyZ++;}
                }
                neprepisujRadky=neprepisujRadkyZ;
                shodaL=false; shodaU=false;
            }
        }
    }
//cout<<endl<<"neprepisuj radky "<<neprepisujRadky<<endl;
/*for(int i=0;i<neprepisujRadky;i++)
{
    //cout<<"radek "<<i<<endl;
    cout<<mezivypocty[i][0]<<"\t";
    for(int y=1; y<mezivypocty[i][0]*2; y+=2){
        //cout<<mezivypocty[i][y]<<" "<<mezivypocty[i][y+1]<<"\t";
    }
    cout<<endl;
}*/
int a;
for(int i=neprepisujRadky-1; i>0; i--){
        for(int y=0;y<i;y++){
            if(mezivypocty[y][0]>mezivypocty[y+1][0]){
                a=mezivypocty[y+1][0];
                mezivypocty[y+1][0]=mezivypocty[y][0];
                mezivypocty[y][0]=a;
            }
        }
}

vysledek<<mezivypocty[neprepisujRadky-1][0]<<endl;
//}

zadani.close();
vysledek.close();
    return 0;
}
