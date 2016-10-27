#include <iostream>
#include <cmath>

using namespace std;
int vzdalenost(int x1, int y1, int x2, int y2){

    if(x1 == x2){
        return abs(y1-y2);
    }

    if(y1 == y2){
        return abs(x1-x2);
    }

    int answer = 0;

    int a1, a2;
    a1 = abs(x1-x2);
    a2 = abs(y1-y2);

    int a;
    if (a1 < a2) {
        a = a1;

        if(x1 < x2)
            x1 += a;
        else
            x1 -= a;

        if(y1 < y2)
            y1 += a;
        else
            y1 -= a;


    }
    else {
        a = a2;

        if(y1 < y2)
            y1 += a;
        else
            y1 -= a;

        if(x1 < x2)
            x1 += a;
        else
            x1 -= a;
    }

    if(x1 == x2){
        return abs(y1-y2) + a;
    }

    if(y1 == y2){
        return abs(x1-x2) + a;
    }

    else{
        cout << "shit" << endl;
    }


}
int main()
{
    cout << vzdalenost(2, 5, 6, 1) << endl;
    cout << vzdalenost(3, 8, 4, 6) << endl;
    cout << vzdalenost(0, 5, 1, 3) << endl;
    cout << vzdalenost(8, 1, 8, 2) << endl;
    cout << vzdalenost(3, 5, 1, 4) << endl;
    return 0;
}
