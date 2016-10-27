#include <iostream>
#include <graphics.h>
#include<conio.h>
#include<ctime>
#include<stdlib.h>
using namespace std;

int main()
{   initwindow(600,600);


    /*for(int a=10; a++; a<250){
        for(int b=10; b++; b<250){
            if(a>150 and a<250 and b>150 and b<250) circle(a,b,1);
        }
    }*/

    srand(time(NULL));

    for(int a=0; a<5000; a++){
        int polohax = rand()%100+150;
        int polohay = rand()%100+150;
        if(polohax>150 and polohax<250 and polohay<250 and polohay>150)
            circle(polohax,polohay,1);}

    int x=0;
   circle(x,100,10);          /* drawn in white color */
   setcolor(RED);
   circle(200,200,50);          /* drawn in red color   */

   getch();

   return 0;
}
