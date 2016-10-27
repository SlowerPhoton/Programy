#include <iostream>

using namespace std;

int main()
{   int number;
    cin>>number;
    int thousands, hundreds, tens, ones;
    if(number/1000>0){thousands = number/1000; number=number-thousands*1000; }else thousands=0;
    if(number/100>0){hundreds = number/100; number=number-hundreds*100;}  else hundreds=0;
    if(number/10>0){tens = number/10; number=number-tens*10; } else tens=0;
    ones = number; number=number-ones;

    int field[4]={thousands, hundreds, tens, ones};


    for(int i=0;i<4;i++){

        if(i==2 and field[0]>0 and field[1]>0){cout<<"and ";}

        if (i!=2)
        {if(field[i]==1)     cout<<"one";
        else if(field[i]==2) cout<<"two";
        else if(field[i]==3) cout<<"three";
        else if(field[i]==4) cout<<"four";
        else if(field[i]==5) cout<<"five";
        else if(field[i]==6) cout<<"six";
        else if(field[i]==7) cout<<"seven";
        else if(field[i]==8) cout<<"eight";
        else if(field[i]==9) cout<<"nine";}


        if(i==0 and field[0]>0){cout<<" thousand ";}
        else if(i==1 and field[1]>0){cout<<" hundred ";}
        else if(i==2 and field[2]>0){

        if(field[i]==1) cout<<"one";
        else if(field[i]==2) cout<<"two";
        else if(field[i]==3) cout<<"thir";
        else if(field[i]==4) cout<<"four";
        else if(field[i]==5) cout<<"fif";
        else if(field[i]==6) cout<<"six";
        else if(field[i]==7) cout<<"seven";
        else if(field[i]==8) cout<<"eight";
        else if(field[i]==9) cout<<"nine";
        cout<<"ty ";}

    }
    return 0;
}
