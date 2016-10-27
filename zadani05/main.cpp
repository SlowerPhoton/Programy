#include <iostream>

using namespace std;

int nsd(int a, int b){
    while (b != 0){
        int pom = a % b;
        a = b;
        b = pom;
    }
    return a;
}

int main()
{
    int input;
    int posNSD; // posledni NSD
    cin >> posNSD;

    while (true){
        cin >> input;
        if (input <= 0) break;

        posNSD = nsd(posNSD, input);
        cout << posNSD << endl;
    }

    return 0;
}
