#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{   int hand[5];
    int opponent = 30;
    int player   = 30;
    int choice=6;
    int manapool;
    int mana=0;
    int deck[]={1,1,1,1,5,5,4,4,3,3};
    int row=0;
    int damage=0;
    int fury=9;
    int manacheck;
    int health_potion=3;
    bool astral_blessing;

    srand(time(NULL));

                            int b; int c;
                            for(int i=0;i<10;i++)
                            {b=deck[i]; c=rand()%10; deck[i]=deck[c]; deck[c]=b;}

                            for(int i=0;i<5;i++){hand[i]=deck[row];row++;}

while(player>0 and opponent>0)
{
manapool=mana;
manacheck=manapool;
cout<<"opponent: "<<opponent<<"    player: "<<player<<"    mana: "<<mana<<endl;
cout<<"tvoje ruka: ";
for(int i=0;i<5;i++)cout<<hand[i]<<" "; cout<<endl;

astral_blessing=true;

while(choice!=0 and choice!=1){
cin>>choice;

            int a=0;
            while(a==0 and choice!=0){
            a=0;
            for(int i=0;i<6;i++){
            if (hand[i]==choice or choice>100){a=1;}
            }
            if (a!=1) {cout<<"tuto kartu nemas"<<endl; cin>>choice;}}

if      (choice==101) {cout<<"ASTRAL BLESSING: +1 mana, -0 manapool"<<endl;}
else if (choice==102) {cout<<"HEALING TOUCH: heal for 10, -3 manapool"<<endl;}
else if (choice==103) {cout<<"FIREBALL: deal 10 dmg, -3 manapool"<<endl;}
else if (choice==104) {cout<<"SACRIFICIAL PACT: deal 5 dmg, get 5 dmg, -0 manapool"<<endl;}
else if (choice==105) {cout<<"HEALTH POTION: heal for 9 over 3 turns, -2 manapool"<<endl;}
else if (choice==666) {cout<<"opponent: "<<opponent<<"    player: "<<player<<"    mana: "<<mana<<endl;cout<<"tvoje ruka: ";for(int i=0;i<5;i++)cout<<hand[i]<<" "; cout<<endl;}

if      (choice==1 and astral_blessing) {mana++;manacheck=manapool-1;cout<<"The crystals are always handy."<<endl;}
else if (choice==2 and manapool>=3) {player+=10; manapool-=3;cout<<"Ahh, the energy!"<<endl;}
else if (choice==3 and manapool>=3) {opponent-=10; manapool-=3;cout<<"Don\'t you smell something?"<<endl;}
else if (choice==4) {opponent-=5; player-=5; cout<<"That HURTS!"<<endl;}
else if (choice==5 and manapool>=2) {health_potion=0;if(health_potion<3){player+=3;} cout<<"Am I supposed to drink it?!"<<endl;}



            if(manacheck!=manapool or choice==666 or choice==4){
            astral_blessing=false;
            for(int i=0;i<6;i++){
            if (hand[i]==choice){hand[i]=0;i=10;}}}
            else cout<<"Znovu"<<endl;
            manacheck=manapool;}choice=2;

if(health_potion<3){health_potion++;} else health_potion=3;

if(row<9){cout<<"dalsi karta: "<<deck[row+1]<<endl;row++;}
else      {cout<<"fatigue!"<<endl; opponent-=3; player-=3;}

            for(int i=0;i<5;i++){
            if(hand[i]==0){hand[i]=deck[row];i=10;}}

            for(int i=0;i<5;i++){
            int b=hand[i]; if(hand[i]>hand[i+1]){hand[i]=hand[i+1];hand[i+1]=b;}}

damage=rand()%fury; fury++;
cout<<"Nepritel pozveda svuj mec a bere ti "<<damage<<" zivotu!";
player-=damage;
cout<<endl<<endl;


}
if(player<0){cout<<"A svet se zahalil pod pokryvku noci..."<<endl;}
if(opponent<0){cout<<"Strkaje si svuj mec zpet do pochvy, vydavas se na dlouho cestu..."<<endl;}
    return 0;
}
