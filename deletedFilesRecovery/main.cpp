#include <iostream>

using namespace std;

int main()
{
    char c[1000000];

    for(int i = 0; i < 1000000; i++)
    {cout << c[i];
    c[i] = '1';
    }

    return 0;
}
