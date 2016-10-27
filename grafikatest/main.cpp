#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{

  cout << "Test grafiky" << endl;
    //otev�e grafick� okno o ���ce 400px a v��ce 300px
    initwindow(500,400);

    //nakresl� do st�edu okna kru�nici o polom�ru 120px
    circle(200,150,120);
    rectangle(100,100,200,200);

    //�ek� 2 sekundy
    delay(2000);

    //p�epne barvu pera na �lutou
    setcolor(YELLOW);

    //namaluje spoustu �se�ek
   /* for(int x=0;x<400;x=x+3){
        // maluje �se�ku z bodu [200, 0] do bodu [x, 299]
       int z=x;{line(200,150,x,z);
        //chilku �ek��
        delay(5);}
    }*/

    //v�pis textu do grafick�ho okna
    setcolor(RED);
    outtextxy(85,272,"Stisknete nejakou klavesu.");
    moveto(250,200);
    for(int i =0; i<6; i++)
    {
        lineto(250+i*i*10,200+i*i*10);
        cout<<"udelal jsem caru"<<i<<endl;
        delay(2000);
    }
    //�ek� na stisk libovoln� kl�vesy
    getch();

    cout << "Konec testovaciho programu." << endl;
    return 0;
}
