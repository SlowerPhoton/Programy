#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{   bool podminka=true;
    int oxo[10][10]={{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    while (podminka){
    int a,b;
    cin>>a;
    cin>>b;
    a--;
    b--;




    if(oxo[a][b]==0){oxo[a][b]=1;}


    int i=true;
    do{a=rand()%10;b=rand()%10;
    i=true;
    if(oxo[a][b]==0){oxo[a][b]=2; i=false;}} while(i);

    for(int rad=0;rad<10;rad++){
    for(int sl=0;sl<10;sl++){if(oxo[rad][sl]==2)cout<<"x ";if(oxo[rad][sl]==1)cout<<"o ";if(oxo[rad][sl]==0)cout<<". ";}
    cout<<endl;
    }

    int inrow=0;

    for(int i=0; i<10; i++){
    for(int ii=1; ii<10; ii++){if(oxo[i][ii]>0 and oxo[i][ii]==oxo[i][ii-1] )inrow++; else inrow=0; if(inrow>=4){podminka=false;}
    }inrow=0;}

    if(podminka==true){for(int i=0; i<10; i++){
    for(int ii=1; ii<10; ii++){if(oxo[ii][i]>0 and oxo[ii][i]==oxo[ii-1][i] )inrow++; else inrow=0; if(inrow>=4){podminka=false;}
    }inrow=0;}}

    }

    return 0;
}
