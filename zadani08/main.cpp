#include <iostream>
#include <iomanip>

using namespace std;

int pow (int x, int n){
    if (n == 0) return 1;
    if (n == 1) return x;

    return pow(x, n-1)*x;
}

int fact (int x){
    if (x == 0) return 1;
    if (x == 1) return 1;

    return fact(x-1)*x;
}

int main()
{
    /*
    cout << pow(3, 3) << endl;
    cout << fact(5) << endl;
    */

    int x = 1;
    double sum = 0;
    for (int i = 0; i < 30; i++){
        sum += (double) pow(x, i)/fact(i);
    }
    cout << setprecision(10) << sum << endl;

    return 0;
}
