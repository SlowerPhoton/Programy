#include <iostream>
#define N 100

using namespace std;

int main()
{
    bool nmbrs[N];


    for (int i = 2; i < N; i++)
        nmbrs[i] = true;

    for (int i = 2; i < N; i++)
    {
        if (nmbrs[i] == false)
            continue;

        for (int j = 2*i; j < N; j+=i)
            nmbrs[j] = false;
    }

    for (int i = 2; i < N; i++)
        if (nmbrs[i] == true)
            cout << i << endl;

    return 0;
}
