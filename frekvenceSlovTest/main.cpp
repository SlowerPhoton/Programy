//cetnost slov v text.soub
#include <iostream>
#include <fstream>
using namespace std;
struct tslovo{ string sl;
               int poc;
               tslovo *dalsi;
             };
int main()
{
tslovo *zac, *zacz,*nove;
string sl2;
bool neni;
ifstream vst("zdroj.txt");
zacz=NULL;

while(!vst.eof())
{
    vst>>sl2;
    zac=zacz;
    neni=true;
    while(zac!=NULL and neni)
      {
         if(zac->sl==sl2) {zac->poc++;neni=false;break;}
         zac=zac->dalsi;
      }
    if (neni)  { nove= new tslovo;
                 nove->sl=sl2;
                 nove->poc=1;
                 nove->dalsi=zacz;
                 zacz=nove;
               }

}
zac=zacz;
while(zac!=NULL)
    {   cout <<zac->sl<<" "<<zac->poc << endl;
         zac=zac->dalsi;
      }

    return 0;
}
