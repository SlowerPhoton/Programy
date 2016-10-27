#include <iostream>
#include <cmath>

using namespace std;

struct vetev{
    int kam;
    int vzdalenost;

    vetev *next;
    vetev *below = NULL;
};

int vzdalenost(int x1, int y1, int x2, int y2){
    return abs((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

vetev *zacatek = NULL;

int *data;
int kolikDat;

int maxSkoku = 0;

void rekurze(vetev *ukazatel, int sk){

        for(int i=0; i < kolikDat*2; i+=2){

            int vzdalenostH = vzdalenost(data[ukazatel->kam*2],data[ukazatel->kam*2+1],data[i],data[i+1]);
            if(vzdalenostH!=0 && vzdalenostH < ukazatel->vzdalenost){
                vetev *newVetev = new vetev;
                // nadefinuj vazdalenost a kam
                newVetev->vzdalenost = vzdalenostH;
                newVetev->kam = i/2;
                // nadefinuj next - LIFO a zmen below otce, aby ukazovallo na novou vetev
                newVetev->next = ukazatel->below;
                ukazatel->below = newVetev;

                rekurze(newVetev,sk+1);
            }

        }

            if (sk > maxSkoku && ukazatel->kam == kolikDat-1)
                maxSkoku = sk;
}

int main()
{
    /* NACTI DATA
     */

    cin >> kolikDat;

    data = new int[kolikDat*2];
    for(int i = 0; i < kolikDat*2; i+=2){

        // nacti x, y
        int x, y;
        cin >> x;
        cin >> y;

        data[i] = x;
        data[i+1] = y;

    }

    /* VYTVOR PRVNI LINII VETVI
     */

    for(int i = 2; i < kolikDat*2; i+=2){

        vetev *newVetev = new vetev;
        newVetev->kam = i/2;
        newVetev->vzdalenost = vzdalenost(data[0], data[1], data[i], data[i+1]);
        newVetev->next = zacatek;
        zacatek = newVetev;

    }


    /* VYTVAREJ DALSI LINIE VETVI
     * POZN. REKURZE!
     */
     vetev *ukazatel = zacatek;
     while(ukazatel!=NULL){
        rekurze(ukazatel,1);
        ukazatel = ukazatel -> next;
     }

     cout << maxSkoku << endl;

    return 0;
}
