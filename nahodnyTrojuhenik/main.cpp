#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    int n;
    cin >> n;

    int trojuhelniky = 0;
    for (int i = 0; i < n; i++){
        double A = ((double)rand() / RAND_MAX)*2;
        double B = A + ((double)rand() / RAND_MAX)*(2-A);

    //    if ( B>1 and A>B-1 and A<1 ) trojuhelniky++;

        double a = A;
        double b = B - A;
        double c = 2 - B;

        if ( a+b>c and a+c>b and b+c>a ) trojuhelniky++;
    }
    cout << (double) trojuhelniky / (double) n << endl;

    return 0;
}
