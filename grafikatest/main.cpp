#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{

  cout << "Test grafiky" << endl;
    //otevøe grafické okno o šíøce 400px a výšce 300px
    initwindow(500,400);

    //nakreslí do støedu okna kružnici o polomìru 120px
    circle(200,150,120);
    rectangle(100,100,200,200);

    //èeká 2 sekundy
    delay(2000);

    //pøepne barvu pera na žlutou
    setcolor(YELLOW);

    //namaluje spoustu úseèek
   /* for(int x=0;x<400;x=x+3){
        // maluje úseèku z bodu [200, 0] do bodu [x, 299]
       int z=x;{line(200,150,x,z);
        //chilku èekáí
        delay(5);}
    }*/

    //výpis textu do grafického okna
    setcolor(RED);
    outtextxy(85,272,"Stisknete nejakou klavesu.");
    moveto(250,200);
    for(int i =0; i<6; i++)
    {
        lineto(250+i*i*10,200+i*i*10);
        cout<<"udelal jsem caru"<<i<<endl;
        delay(2000);
    }
    //èeká na stisk libovolné klávesy
    getch();

    cout << "Konec testovaciho programu." << endl;
    return 0;
}
