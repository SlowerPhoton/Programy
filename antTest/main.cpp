#include <iostream>
#include <ctime>
#include <stdlib.h>
//#include <random>



using namespace std;

int main()
{   int xPoloha;
    int yPoloha;

    srand(time(NULL));

    for(int i = 0; i < 100; i++){
        char a = (char) rand()%128;
        cout << /*(char)*/  a << " " << endl;
    }
    return 0;
}
