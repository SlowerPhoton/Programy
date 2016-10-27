#include <iostream>
#include <math.h>

using namespace std;

int main()
{   int pocetUloh;
    cin>>pocetUloh;
    int ulohy[pocetUloh][2];
    for(int i=0; i<pocetUloh; i++){
        cin>>ulohy[i][0]; //cout<<ulohy[i][0]<<" ";
        cin>>ulohy[i][1]; //cout<<ulohy[i][1]<<endl;
    }
    int prvocisla[5]={2,3,5,7,11};
    int prvocinitele1[5]={0,0,0,0,0};
    int prvocinitele2[5]={0,0,0,0,0};

    int a;
    for(int i=0; i<pocetUloh; i++){
        for(int y=0; y<2; y++){
            int odmocnina=sqrt(ulohy[i][y]); cout<<"odmocnina "<<odmocnina<<endl;
            for(int z=0; z<6;z++){if(odmocnina>prvocisla[z]){a=z;break;}}
            for(a; a>0; a--){
                while(ulohy[i][y]%prvocisla[a]==0){ulohy[i][y]/=prvocisla[a];if(y==0)prvocinitele1[a]++;
                                       if(y==1)prvocinitele2[a]++;}
            }
        }
    }
    for(int i=0; i<6; i++)
    cout<<prvocinitele1[i]<<" "<<prvocinitele1[i]<<endl;

    return 0;
}
