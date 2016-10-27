#include <iostream>
#include <graphics.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{   srand(time(NULL));
    initwindow(600,600);
    float souradniceBodu[100][2];

    for(int i=0; i<100; i++)
    {    souradniceBodu[i][0]=rand()%600;
         souradniceBodu[i][1]=rand()%600;
         circle(souradniceBodu[i][0],souradniceBodu[i][1],1);
    }
    delay(100);

 /*   //x599, y 0->599
    x=599;
    for(y=0;y<600;y++)
    line(300,300,x,y);

    //y599 x 599->0
    y=599;
    for(x=599;x>-1;x--)
    line(300,300,x,y);

    //x0 y 599->0
    x=0;
    for(y=599;y>-1;y--)
    line(300,300,x,y);

    //y0, x 0->599
    y=0;
    for(x=0;x<600;x++)
    line(300,300,x,y);*/

    float k;

    for(int x1=0;x1<600;x1++)
    {
            //line(x1,0,599-x1,599);
            //line(0,600-x1,599,x1-1);
            //k=(-599.0/(2*x1+599.0));
            for(int a=0;a<100;a++){

                if((x1-souradniceBodu[a][0])!=0)if((-599.0/(2*x1+599.0))==(-1.0*souradniceBodu[a][1])/(x1-souradniceBodu[a][0]) or (-599.0/(2*x1+599.0))==(600-x1-souradniceBodu[a][1])/(-1*souradniceBodu[a][0]) ){line(x1,0,599-x1,599); /*delay(5);*/}
                if((x1-souradniceBodu[a][0])!=0)cout<<(-599.0/(2*x1+599.0))<<"  "<<(-1.0*souradniceBodu[a][1])/(x1-souradniceBodu[a][0])<<endl;}
            //cout << /*setprecision(5) <<*/ k << endl;
            //delay(10);
    }
   /* for(int y1=600;y1>-1;y1--)
    {

            delay(5);
    }*/

    getch();
    return 0;
}
